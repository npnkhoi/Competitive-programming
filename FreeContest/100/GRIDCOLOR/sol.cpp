#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, k, total;
vector<int> adj[N];
set<pair<int, int>> edge;
int lab[N], color[N], hor[N][N], ver[N][N];

int root(int u) {
	// cerr << u << '\n';
	if (lab[u] < 0) return u;
	else return lab[u] = root(lab[u]);
}

void join(int u, int v) {
	// cerr << u << ' ' << v << '\n';
	u = root(u);
	// cerr << u << ' ';
	v = root(v);
	if (u == v) return;
	// cerr << v << '\n';
	if (lab[u] < lab[v]) {
		lab[v] = u;
	} else {
		lab[v] -= lab[u] == lab[v];
		lab[u] = v;
	}
}

void dfs(int u) {
	set<int> mark;
	for (int v : adj[u]) {
		if (color[v] != 0) mark.insert(color[v]);
	}
	for (int i = 1; i <= k; ++ i) {
		if (mark.find(i) == mark.end()) {
			color[u] = i;
			break;
		}
	}
	if (color[u] == 0) {
		printf("-1");
		exit(0);
	}
	for (int v : adj[u]) {
		if (color[v] != 0) continue;
		dfs(v);
	}
}

int id(int i, int j) {
	return m * (i - 1) + j;
}

void transform(int mask) {
	int idx = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j < m; ++ j) {
			// cerr << i << ' ' << j << '\n';
			hor[i][j] ^= (mask >> idx & 1);
			if (hor[i][j]) {
				join(id(i, j), id(i, j + 1));
			}
			idx ++;
		}
	}
	for (int i = 1; i < n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			// cerr << i << ' ' << j << '\n';
			ver[i][j] ^= (mask >> idx & 1);
			if (ver[i][j]) {
				// cerr << "joining\n";
				join(id(i, j), id(i + 1, j));
				// cerr << "done joining\n";
			}
			idx ++;
		}
	}
}

bool check() {
	bool ok = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j < m; ++ j) {
			if (hor[i][j] == 0 && root(id(i, j)) == root(id(i, j + 1))) {
				ok = 0;
				break;
			}
		}
	}
	for (int i = 1; i < n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if (ver[i][j] == 0 && root(id(i, j)) == root(id(i + 1, j))) {
				ok = 0;
				break;
			}
		}
	}
	return ok;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int cntE = 0;
	char ch;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m - 1; ++ j) {
			scanf(" %c", &ch);
			hor[i][j] = (ch == 'E');
			cntE += (hor[i][j]);
		}
	}
	for (int i = 1; i <= n - 1; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			scanf(" %c", &ch);
			ver[i][j] = (ch == 'E');
			cntE += (ver[i][j]);
		}
	}
	total = 2 * n * m - n - m;
	if (k == 1) {
		if (4 * cntE >= 3 * total) {
			for (int i =1; i <= n; ++ i) {
				for (int j = 1; j <= m; ++ j) {
					printf("1 ");
				}
				printf("\n");
			}
		} else printf("-1\n");
	} else {
		for (int mask = 0; mask < (1 << 2 * m * n - m - n); ++ mask) {
			if (4 * __builtin_popcount(mask) > total) continue;
			memset(lab, -1, sizeof lab);

			transform(mask);
			bool ok = check();
			transform(mask);
			if (!ok) continue;

			for (int i = 1; i <= 15; ++ i) adj[i].clear();
			edge.clear();
			for (int i = 1; i <= n; ++ i) {
				for (int j = 1; j <= m; ++ j) {
					if (i < n && root(id(i, j)) != root(id(i + 1, j))) {
						edge.insert({root(id(i, j)), root(id(i + 1, j))});
					}
					if (j < m && root(id(i, j)) != root(id(i, j + 1))) {
						edge.insert({root(id(i, j)), root(id(i, j + 1))});
					}
				}
			}
			for (auto p : edge) {
				adj[p.first].push_back(p.second);
				adj[p.second].push_back(p.first);
			}
			memset(color, 0, sizeof color);
			dfs(root(id(1, 1)));
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					printf("%d ", color[root(id(i, j))]);
				}
				printf("\n");
			}
			return 0;
		}
	}
}