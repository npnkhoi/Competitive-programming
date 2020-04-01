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
int lab[N], f[M];
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

void renumerate() {	
	sort(nodes.begin(), nodes.end());
	nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
	n = nodes.size();
	for (int i = 1; i <= m; ++ i) {
		e[i].first = upper_bound(nodes.begin(), nodes.end(), e[i].first) - nodes.begin();
		e[i].second = upper_bound(nodes.begin(), nodes.end(), e[i].second) - nodes.begin();
	}
}

struct STNode {
	int l, r, val, lazy;
};


int leaf[N];

struct LazySegmentTree {
public:
	vector<STNode> a;
	void init(int siz) {
		a.resize(4 * siz);
		build(1, 1, siz);
	}
	void build(int p, int l, int r) {
		a[p].l = l;
		a[p].r = r;
		a[p].val = oo;
		a[p].lazy = oo;
		if (l < r) {
			int mid = (l + r) / 2;
			build(2 * p, l, mid);
			build(2 * p + 1, mid + 1, r);
		} else {
			leaf[l] = p;
		}
	}
	void down(int p) {
		a[2 * p].lazy = min(a[2 * p].lazy, a[p].lazy);
		a[2 * p + 1].lazy = min(a[2 * p + 1].lazy, a[p].lazy);
		a[p].val = min(a[p].val, a[p].lazy);
		a[p].lazy = oo;
	}
	void update(int p, int l, int r, int val) {
		down(p);
		if (a[p].l > r || l > a[p].r) return;
		if (l <= a[p].l && a[p].r <= r) {
			a[p].lazy = val;
			down(p);
			return;
		}
		update(2 * p, l, r, val);
		update(2 * p + 1, l, r, val);
		// depend on type of query
		a[p].val = min(a[2 * p].val, a[2 * p + 1].val);
	}
	int get(int p, int l, int r) {
		down(p);
		if (a[p].l > r || l > a[p].r) return oo;
		if (l <= a[p].l && a[p].r <= r) {
			return a[p].val;
		}
		// depend on type of query
		return min(get(2 * p, l, r), get(2 * p + 1, l, r));
	}
} IT;

int counter;
int sz[N], dep[N], par[N], upEdge[N];
int num[N], head[N], depOfChain[N];


void dfsInit(int u, int fa) {
	// compute sz[], dep[] and par[] for HLD
	// compute upEdge[] for Segment Tree
	num[u] = 1;
	par[u] = fa;
	sz[u] = 1;
	for (ii v : adj[u]) {
		if (v.first != fa) {
			dep[v.first] = dep[u] + 1;
			upEdge[v.first] = v.second;
			dfsInit(v.first, u);
			sz[u] += sz[v.first];
		}
	}
}

void dfsHLD(int u) {
	// compute num[u], head[], depOfChain[] for HLD
	num[u] = ++ counter;
	// cerr << "dfs hld" << u << " " << counter << "\n";
	int heavy = -1;
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		ii v = adj[u][i];
		if (v.first == par[u]) continue;
		if (heavy == -1 || (sz[heavy] < sz[v.first])) {
			heavy = v.first;
		}
	}
	// cerr << "heavy = " << heavy << "\n";
	if (heavy != -1) {
		head[heavy] = head[u];
		depOfChain[heavy] = depOfChain[u];
		dfsHLD(heavy);
	}
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		ii v = adj[u][i];
		if (v.first != par[u] && v.first != heavy) {
			head[v.first] = v.first;
			depOfChain[v.first] = depOfChain[u] + 1;
			dfsHLD(v.first);
		}
	}
	// cerr << u << " " << num[u] << " " << head[u] << "\n";
}

int LCA(int u, int v) {
	if (depOfChain[u] > depOfChain[v]) {
		swap(u, v);
	}
	while (depOfChain[v] > depOfChain[u]) {
		v = par[head[v]];
	} 
	while (head[u] != head[v]) {
		u = par[head[u]];
		v = par[head[v]];
	}
	if (dep[u] < dep[v]) return u;
	else return v;
}

void updatePath(int u, int v, int val, LazySegmentTree &ST) {
	// cerr << "update path " << u << " " << v << "\n";
	while (depOfChain[u] < depOfChain[v]) {
		ST.update(1, num[head[v]], num[v], val);
		// cerr << "update " << num[head[v]] << " " << num[v] << "\n";
		v = par[head[v]];
 	}
	// if (num[u] > num[v]) swap(u, v);
	if (num[u] < num[v]) {
		ST.update(1, num[u] + 1, num[v], val);
		// cerr << u << " " << v << "\n";
		// cerr << num[u] + 1 << " " << num[v] << "\n";
	}
}

int main() {
	// freopen("LKYEDGE.inp", "r", stdin);
	// freopen("LKYEDGE.out", "w", stdout);
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &m);
		nodes.clear();
		memset(f, 0, sizeof f);
		for (int i = 1; i <= m; ++ i) {
			int u, v;
			scanf("%d%d", &e[i].first, &e[i].second);
			nodes.push_back(e[i].first);
			nodes.push_back(e[i].second);
		}
		renumerate();

		for (int startEdge = 1; startEdge <= m; ++ startEdge) {
			// cerr << "startEdge = " << startEdge << "\n";

			memset(lab, -1, sizeof lab);
			for (int i = 1; i <= n; ++ i) {
				adj[i].clear();
			}
			inTree.clear();
			outTree.clear();

			for (int i = startEdge; i <= m; ++ i) {
				int u = e[i].first, v = e[i].second;
				if (root(u) == root(v)) {
					f[i] += m - i + 1;
					outTree.push_back(i);
				} else {
					merge(u, v);
					adj[u].push_back(make_pair(v, i));
					adj[v].push_back(make_pair(u, i));
					inTree.push_back(i);
				}
			}
			
			// Init HLD + IT ---------------------------
			// cerr << "dfs init\n";
			memset(num, 0, sizeof num);
			for (int i = 1; i <= n; ++ i) {	
				if (!num[i]) {
					dep[i] = 0;
					dfsInit(i, -1);
				}
			}
			// cerr << "dfs hld\n";
			memset(num, 0, sizeof num);
			counter = 0;
			for (int i = 1; i <= n; ++ i) {
				if (!num[i]) {
					head[i] = i;
					depOfChain[i] = 1;
					dfsHLD(i);
				}
			}

			IT.init(n);
			// for (int i = 1; i <= n; ++ i) {
			// 	cerr << i << " " << num[i] << "\n";
			// }
			for (int x : outTree) {
				int u = e[x].first;
				int v = e[x].second;
				int t = LCA(u, v);

				updatePath(t, u, x, IT);
				updatePath(t, v, x, IT);
			}
			// for (int i = 1; i <= 4; ++ i) {
			// 	cerr << IT.get(1, i, i) << "\n";
			// }
			for (int x : inTree) {
				int u = e[x].first, v = e[x].second;
				if (num[u] > num[v]) swap(u, v);
				int tmp = IT.get(1, num[v], num[v]);
				// cerr << x << " " << v << "  " << tmp << "\n"; 
				if (tmp != oo) {
					f[x] += m - tmp + 1;
				}
			}
			// for (int i = 1; i <= m; ++ i) {
			// 	cerr << f[i] << ' ';
			// }			
			// cerr << '\n';
		}

		for (int i = 1; i <= m; ++ i) {
			printf("%d ", f[i]);
		}
		printf("\n");
	}
}