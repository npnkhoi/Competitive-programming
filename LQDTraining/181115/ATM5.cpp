#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int oo = 1e9 + 7;

int n, m, s, p;
vector<int> adj[N], dag[N], topo;
int cntVtx, cntSCC, res;
stack<int> st;
int canEnd[N], bigEnd[N], low[N], num[N], onSt[N], id[N], a[N], money[N], f[N], mark[N];

void input() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i) 
		scanf("%d", &a[i]);
	scanf("%d%d", &s, &p);
	for (int i = 1; i <= p; ++ i) {
		int u;
		scanf("%d", &u);
		canEnd[u] = 1;
	}
}

void tarjan(int u) {
	st.push(u);
	onSt[u] = 1;
	num[u] = low[u] = ++ cntVtx;
	for (int v : adj[u]) {
		if (num[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (onSt[v]) {
			low[u] = min(low[u], num[v]);
		}
	}
	if (num[u] == low[u]) {
		++ cntSCC;
		while (1) {
			int v = st.top();
			st.pop();
			onSt[v] = 0;
			id[v] = cntSCC;
			money[cntSCC] += a[v];
			bigEnd[cntSCC] |= canEnd[v];
			if (v == u) break;
		}
	}
}

void formDAG() {
	for (int i = 1; i <= n; ++ i) {
		if (num[i] == 0) tarjan(i);
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j : adj[i]) {
			if (id[j] != id[i]) {
				dag[id[i]].push_back(id[j]);
			}
		}
	}
}

void topoSort(int u) {
	mark[u] = 1;
	for (int v : dag[u]) {
		if (!mark[v]) {
			topoSort(v);
		}
	}
	topo.push_back(u);
}

void dp() {
	for (int i = 1; i <= cntSCC; ++ i) {
		if (mark[i] == 0) topoSort(i);
	}
	reverse(topo.begin(), topo.end());
	// cerr << "topo: "; for (int x : topo) cerr << x << " "; cerr << "\n";
	for (int x : topo) f[x] = - oo;
	f[id[s]] = money[id[s]];
	// cerr << "f: "; for (int i = 1; i <= cntSCC; ++ i) cerr << f[i] << " "; cerr << "\n";
	// cerr << "bigEnd: "; for (int i = 1; i <= cntSCC; ++ i) cerr << bigEnd[i] << " "; cerr << "\n";
	for (int x : topo) {
		// cerr << "f " << x << " " << f[x] << "\n";
		if (f[x] == - oo) continue;
		if (bigEnd[x]) res = max(res, f[x]);
		for (int y : dag[x]) {
			f[y] = max(f[y], f[x] + money[y]);
		}
	}
}

int main() {
	// freopen("test.inp", "r", stdin);
	input();
	formDAG();
	// cerr << "id: "; for (int i = 1; i <= n; ++ i) cerr << id[i] << " "; cerr << "\n";
	// cerr << cntSCC << "\n";
	// for (int i = 1; i <= cntSCC; ++ i) cerr << money[i] << " "; cerr << "\n";
	dp();
	printf("%d\n", res);
}