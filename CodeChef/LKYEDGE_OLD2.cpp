#include <bits/stdc++.h>
using namespace std;

const int M = 5e3 + 5;
const int N = 1e4 + 5;
const int LOG = 14;
const int oo = 1e9 + 7;

typedef pair<int, int> ii;

int m, n;
vector<int> nodes, inTree, outTree, actList[N], deactList[N];
vector<ii> adj[N];
ii e[M];
int lab[N], f[M], mark[N], dep[N], anc[N][LOG + 2], active[M];
priority_queue<int, vector<int>, greater<int> > heap;

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
	mark[u] = 1;
	cerr << "dfs " << u << '\n';
	for (ii v : adj[u]) {
		if (v.first == par) continue;
		// upEdge[v.first][0] = v.second;
		anc[v.first][0] = u;
		dep[v.first] = dep[u] + 1;
		dfs(v.first, u);
	}
}

void calc(int u, int par) {
	cerr << "calc " << u << '\n';
	mark[u] = 1;
	// cerr << "active\n";
	// for (int i = 1; i <= m; ++ i) {
	// 	cerr << active[i] << " ";
	// }
	// cerr << "\n";
	for (ii v : adj[u]) {
		for (int x : actList[u]) {
			active[x] = 1;
			heap.push(x);
		}
		if (v.first == par) continue;
		while (!heap.empty() && !active[heap.top()]) {
			heap.pop();
			cerr << "pop\n";
		}
		if (!heap.empty()) {
			f[v.second] += m - heap.top() + 1;
			cerr << "update edge " << v.second << " " << heap.top() << "\n";
		}
		calc(v.first, u);
	}
	for (int x : deactList[u]) {
		active[x] = 0;
	}
}

int LCA(int u, int v) { // u and v in the same tree
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = LOG; i >= 0; -- i) {
		if ((1 << i) <= dep[v] - dep[u]) {
			v = anc[v][i];
		}
	}
	if (u == v) return u;
	for (int i = LOG; i >= 0; -- i) {
		if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i]) {
			u = anc[u][i], v = anc[v][i];
		} 
	}
	return anc[u][0];
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
		n = nodes.size();
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
			// inTree.clear();
			outTree.clear();
			for (int i = 1; i <= n; ++ i) {
				adj[i].clear();
			}

			for (int i = startEdge; i <= m; ++ i) {
				int u = e[i].first, v = e[i].second;
				if (root(u) == root(v)) {
					f[i] += m - i + 1;
					// cerr << m - i + 1 << '\n';
					outTree.push_back(i);
					cerr << i << " is out\n";
				} else {
					merge(u, v);
					adj[u].push_back(make_pair(v, i));
					adj[v].push_back(make_pair(u, i));
					// inTree.push_back(i);
					cerr << i << " is in\n";
				}
			}


			memset(mark, 0, sizeof mark);
			for (int i = 1; i <= n; ++ i) {	
				if (!mark[i]) dfs(i, -1);
			}
			for (int d = 1; d <= LOG; ++ d) {
				for (int i = 1; i <= 2 * m; ++ i) {
					if ((1 < d) <= dep[i]) {
						anc[i][d] = anc[anc[i][d - 1]][d - 1];
					}
				}
			}
			for (int i = 1; i <= n; ++ i) {
				actList[i].clear();
				deactList[i].clear();
			}
			for (int x : outTree) {
				int u = e[x].first, v = e[x].second;
				int t = LCA(u, v);
				cerr << u << " " << v << " LCA : " << t << "\n";
				actList[t].push_back(x);
				deactList[u].push_back(-x);
				deactList[v].push_back(-x);
			}
			memset(mark, 0, sizeof mark);
			memset(active, 0, sizeof active);
			while (!heap.empty()) heap.pop();
			for (int i = 1; i <= n; ++ i) {
				if (!mark[i]) calc(i, -1);
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