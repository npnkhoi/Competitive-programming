#include <bits/stdc++.h>
using namespace std;

const int M = 5e3 + 5;
const int LOG = 14;
const int oo = 1e9 + 7;

typedef pair<int, int> ii;

int m;
vector<int> nodes, inTree, outTree;
vector<ii> adj[2*M];
ii e[M];
int lab[2*M], f[M], mark[2*M], dep[2*M], anc[2*M][LOG + 2], upEdge[2*M][LOG + 2];

int root(int u) {
	if (lab[u] < 0) return u;
	else return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
	u = root(u), v = root(v);
	if (lab[u] < lab[v]) {
		lab[v] = u;
	} else {
		lab[u] = v;
		lab[v] -= (lab[u] == lab[v]);
	}
}

void dfs(int u, int par) {
	for (ii v : adj[u]) {
		if (v.first == par) continue;
		upEdge[v.first][0] = v.second;
		anc[v.first][0] = u;
		dep[v.first] = dep[u] + 1;
		dfs(v.first, u);
	}
}

int getMinEdge(int u, int v) { // u and v in the same tree
	if (dep[u] > dep[v]) swap(u, v);
	int res = oo;
	for (int i = LOG; i >= 0; -- i) {
		if ((1 << i) <= dep[v] - dep[u]) {
			res = min(res, upEdge[v][i]);
			v = anc[v][i];
		}
	}
	if (u == v) return res;
	for (int i = LOG; i >= 0; -- i) {
		if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i]) {
			res = min(res, min(upEdge[u][i], upEdge[v][i]));
		} 
	}
	return min(res, min(upEdge[u][0], upEdge[v][0]));
}

int main() {
	freopen("LKYEDGE.inp", "r", stdin);
	// freopen("LKYEDGE.out", "w", stdout);
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &m);
		nodes.clear();
		for (int i = 1; i <= m; ++ i) {
			int u, v;
			scanf("%d%d", &e[i].first, &e[i].second);
			nodes.push_back(e[i].first);
			nodes.push_back(e[i].second);
		}
		// renumerate
		sort(nodes.begin(), nodes.end());
		nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
		for (int i = 1; i <= m; ++ i) {
			e[i].first = upper_bound(nodes.begin(), nodes.end(), e[i].first) - nodes.begin();
			e[i].second = upper_bound(nodes.begin(), nodes.end(), e[i].second) - nodes.begin();
		}

		// cerr << "edges\n";
		// for (int i = 1; i <= m; ++ i) {
		// 	cerr << e[i].first << " " << e[i].second << "\n";
		// }

		memset(f, 0, sizeof f);

		for (int startEdge = 1; startEdge <= m; ++ startEdge) {
			cerr << "startEdge = " << startEdge << "\n";
			memset(lab, -1, sizeof lab);
			inTree.clear();
			outTree.clear();

			for (int i = startEdge; i <= m; ++ i) {
				int u = e[i].first, v = e[i].second;
				if (root(u) == root(v)) {
					f[i] += m - i + 1;
					// cerr << m - i + 1 << '\n';
					outTree.push_back(i);
					cerr << i << " is out\n";
				} else {
					merge(u, v);
					inTree.push_back(i);
					cerr << i << " is in\n";
				}
			}

			memset(lab, -1, sizeof lab);
			for (int i = 1; i <= 2 * m; ++ i) {
				adj[i].clear();
			}
			for (int x : outTree) {
				int u = e[x].first, v = e[x].second;
				if (root(u) != root(v)) {
					merge(u, v);
					adj[u].push_back(make_pair(v, x));
					adj[v].push_back(make_pair(u, x));
					cerr << "edge " << u << " " << v << " " << x << "\n";
				}
			}
			memset(mark, 0, sizeof mark);
			memset(dep, 0, sizeof dep);
			for (int i = 1; i <= 2 * m; ++ i) {
				if (mark[i] == 0) {
					dfs(i, -1);
				}
			}
			for (int d = 1; d <= LOG; ++ d) {
				for (int i = 1; i <= 2 * m; ++ i) {
					if ((1 < d) <= dep[i]) {
						anc[i][d] = anc[anc[i][d - 1]][d - 1];
						upEdge[i][d] = min(upEdge[i][d - 1], upEdge[anc[i][d - 1]][d - 1]);
					}
				}
			}
			for (int x : inTree) {
				// cerr << x << " is in\n";
				int u = e[x].first, v = e[x].second;
				if (root(u) == root(v)) {
					f[x] += m - getMinEdge(u, v) + 1;
					cerr << m - getMinEdge(u, v) + 1 << "\n";
				}
			}
			for (int i = 1; i <= m; ++ i) {
				cerr << f[i] << " ";
			}
			cerr << "\n";
		}
		for (int i = 1; i <= m; ++ i) {
			printf("%d ", f[i]);
		}
		printf("\n");
	}
}