#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

const long long oo = 1e18 + 7;
const int N = 1e5 + 5;
const vector<long long> INF = {oo, oo};

struct Pack {
	long long dist;
	int vtx, pos, slope;
	// slope: 0 -> decrease; 1 -> increase
	Pack(long long a, int b, int c, int d): dist(a), vtx(b), pos(c), slope(d) {}
};

bool operator > (const Pack &a, const Pack &b) {
	return a.dist > b.dist;
}

struct Link {
	int vtx, wei, pos;
	Link(int a, int b, int c): vtx(a), wei(b), pos(c) {}
};

int n, m, s, d;
vector<vector<long long> > dist[N];
vector<Link> adj[N];
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;
// set<pair<int, int> > edge; 
long long res;


bool checkRela(int e1, int e2, int flag) {
	// cerr << "checkRela " << e1 << " " << e2 << " " << flag << "\n";
	if (e1 > e2) return flag == 0;
	else if (e1 < e2)  return flag == 1;
	else return false;
}

int main() {
	// double Time = clock();
	// freopen("SPPATH.inp", "r", stdin);
	// freopen("SPPATH.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);

		// if (u == v) continue;
		// if (u > v) swap(u, v);
		// if (edge.find(make_pair(u, v)) != edge.end()) continue;
		// edge.insert(mp(u, v));
		// cerr << u << " " << v << " " << c << "\n";
		int posInU = adj[u].size(), posInV = adj[v].size();
		adj[u].push_back(Link(v, c, posInV));
		adj[v].push_back(Link(u, c, posInU));
		
		// dist[u].push_back(INF);
		// dist[v].push_back(INF);
	}
	// for (int i = 1; i <= n; ++ i) {
	// 	sort(adj[i].begin(), adj[i].end(), [](const Link &a, const Link &b){
	// 		return a.wei < b.wei;
	// 	});
	// }
	for (int i = 1; i <= n; ++ i) {
		dist[i].resize(adj[i].size());
		int tmp = dist[i].size();
		for (int j = 0; j < tmp; ++j) {
			dist[i][j].resize(2);
			dist[i][j][0] = dist[i][j][1] = oo;
		}
	}
	scanf("%d%d", &s, &d);

	for (Link v : adj[s]) {
		heap.push(Pack(v.wei, v.vtx, v.pos, 0));
		dist[v.vtx][v.pos][0] = v.wei;
		// cerr << ""
		// cerr << v.vtx << " " << v.pos << " " << v.wei << "\n";
	}

	// double Time2 = clock();
	// int heapSz = 0;
	// int cnt = 0;
	// cerr << adj[3][0].wei << "\n";
	while (!heap.empty()) {
		Pack t = heap.top();
		heap.pop();
		// cerr << "pop\n";

		if (t.dist != dist[t.vtx][t.pos][t.slope]) continue;

		// if (t.vtx == d) {
		// 	cnt ++;
		// 	if (cnt == 2 * adj[d].size()) break;
		// }
		for (Link v : adj[t.vtx]) {
		// for (int i = 0; i < adj[t.vtx].size(); ++i) {
		// 	Link v = adj[t.vtx][i];
			// cerr << "consider " << t.vtx << " " << v.vtx << "\n";
			// cerr << t.vtx << " " << t.pos << " " << adj[t.vtx][t.pos].wei << "\n";
			if (checkRela(adj[t.vtx][t.pos].wei, v.wei, t.slope) && t.dist + v.wei < dist[v.vtx][v.pos][t.slope ^ 1]) {
				dist[v.vtx][v.pos][t.slope ^ 1] = t.dist + v.wei;
				heap.push(Pack(t.dist + v.wei, v.vtx, v.pos, t.slope ^ 1));
				// cerr << "reach " << v.vtx << " " << t.dist + v.wei << "\n";
			}
		}
		// heapSz = max(heapSz, (int) heap.size());
	}
	// cerr << "Dijsktra: " << (clock() - Time2) / CLOCKS_PER_SEC << "\n";
	// cerr << "Heap size: " << heapSz << "\n";

	res = oo;
	int siz = adj[d].size();
	for (int i = 0; i < siz; ++ i) {
		res = min(res, min(dist[d][i][0], dist[d][i][1]));
	}
	if (res == oo) printf("-1");
	else printf("%lld", res);
	// cerr << "Time: " << (clock() - Time)/CLOCKS_PER_SEC; 
}