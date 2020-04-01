#include <bits/stdc++.h>
using namespace std;

const int maxv = 55;
const int maxe = 2505;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int oo = 1e9 + 7;

struct Matching {
    int n;
    vector< vector<int> > ke;
    vector< bool > seen;
    vector< int > matchL, matchR;

    Matching(int n) : n(n), ke(n), seen(n, false), matchL(n, -1), matchR(n, -1) {
    }

    void addEdge(int u, int v) {
        ke[u].push_back(v);
    }

    bool bpm(int u) {
        for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v) {
            if (seen[*v]) continue;
            seen[*v] = true;

            if (matchR[*v] < 0 || bpm(matchR[*v])) {
                matchL[u] = *v;
                matchR[*v] = u;
                return true;
            }
        }
        return false;
    }

    int match() {
        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int i = 0; i < n; ++i) seen[i] = false;
            if (bpm(i)) ++res;
        }
        return res;
    }
};

int height, width, m;
int dist_source_key[maxv], dist_key_door[maxv][maxv], dist[maxv][maxv];
pair<int, int> source;
vector<pair<int, int> > keys, doors;


bool check(int lim) {
	Matching matching(m + 3);
	for (int i = 0; i < m; ++ i) {
		for (int j = 0; j < m; ++ j) {
			if (dist_source_key[i] + dist_key_door[i][j] <= lim) {
				// cerr << "add edge " << i << ' ' << j << '\n';
				matching.addEdge(i + 1, j + 1);
				// edmonds.add(j + 1, i + 1);
			}
		}
	}
	// cerr << "maxmat: " << edmonds.maxmat() << '\n';
	return (matching.match() == m);
}

bool inBoard(int x, int y) {
	return (0 <= x) && (x < height) && (0 <= y) && (y < width);
}

void flood(std::vector<std::string> &islandMap, int x, int y) {
	for (int i = 0; i < height; ++ i) {
		for (int j = 0; j < width; ++ j) {
			dist[i][j] = oo;
		}
	}

	queue<pair<int, int> > q;
	dist[x][y] = 0;
	q.push({x, y});

	while (!q.empty()) {
		pair<int, int> t = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++ dir) {
			int u = t.first + dx[dir], v = t.second + dy[dir];
			if (inBoard(u, v) && dist[u][v] == oo && islandMap[u][v] != '2') {
				dist[u][v] = dist[t.first][t.second] + 1;
				q.push({u, v});
			}
		}
	}
	// cerr << "flood from " << x << ' ' << y << '\n';
	// for (int i = 0; i < n; ++ i) {
	// 	for (int j = 0; j < n; ++ j) {
	// 		cerr << dist[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
}

int treasurePath(std::vector<std::string> islandMap) {
	height = islandMap.size();
	width = islandMap[0].size();

	for (int i = 0; i < height; ++ i) {
		for (int j = 0; j < width; ++ j) {
			if (islandMap[i][j] == '0') {
				source = {i, j};
			} else if (islandMap[i][j] == '3') {
				keys.push_back({i, j});
				// cerr << "key " << i << ' ' << j << '\n';
			} else if (islandMap[i][j] == '4') {
				doors.push_back({i, j});
				// cerr << "door " << i << ' ' << j << '\n';
			}
		}
	}
	// cerr << source.first << ' ' << source.second << '\n';

	m = keys.size();
	flood(islandMap, source.first, source.second);
	for (int i = 0; i < m; ++ i) {
		dist_source_key[i] = dist[keys[i].first][keys[i].second];
	}
	for (int i = 0; i < m; ++ i) {
		flood(islandMap, keys[i].first, keys[i].second);
		for (int j = 0; j < m; ++ j) {
			dist_key_door[i][j] = dist[doors[j].first][doors[j].second];
		}
	}

	// cerr << "soure -> key: \n";
	// for (int i = 0; i < m; ++ i) {
	// 	cerr << dist_source_key[i] << ' ';
	// }
	// cerr << '\n';
	// cerr << "key -> door: \n";
	// for (int i = 0; i < m; ++ i) {
	// 	for (int j = 0; j < m; ++ j) {
	// 		cerr << dist_key_door[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
	// cerr << '\n';


	int l = 0, r = 2 * height * width, mid, bs = r;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			bs = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (bs == 2 * height * width) return -1;
	return bs;
}

int main() {
	vector<string> test = {"01111322224", "11111112221", "11111111111", "31111111114"};
	cerr << treasurePath(test);
}