#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, w, na, nb, cntA, cntB;
int mark[N], type[N];
vector<int> adj[N];
vector<pair<int, int> > edgeW;

void dfs(int u) {
	mark[u] = 1;
	if (type[u] == 0) cntA ++;
	else if (type[u] == 1) cntB ++;
	for (int v : adj[u]) {
		if (!mark[v]) dfs(v);
	}
}

int main() {
	// cerr << "start \n";
	freopen("PATH.inp", "r", stdin);
	freopen("PATH.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &m, &w, &na, &nb);
	for (int i = 1; i <= m; ++ i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		if (c < w) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		} else if (c == w) {
			edgeW.push_back(make_pair(u, v));
		}
	}
	int u;
	memset(type, -1, sizeof type);
	for (int i = 1; i <= na; ++ i) {
		scanf("%d", &u);
		type[u] = 0; // :)
	}
	for (int i = 1; i <= nb; ++ i) {
		scanf("%d", &u);
		type[u] = 1;
	}

	long long res = 0;
	for (int u = 1; u <= n; ++ u) {
		if (!mark[u]) {
			cntA = cntB = 0;
			dfs(u);
			// cerr << cntA << " " << cntB << "\n";
			res -= 1LL * cntA * cntB;
		}
	}
	// cerr << res << "\n";
	for (pair<int, int> t : edgeW) {
		adj[t.first].push_back(t.second);
		adj[t.second].push_back(t.first);
	}
	memset(mark, 0, sizeof mark);
	for (int i = u; u <= n; ++ u) {
		if (!mark[u]) {
			cntA = cntB = 0;
			dfs(u);
			// cerr << cntA << " " << cntB << "\n";
			res += 1LL * cntA * cntB;
		}
	}
	printf("%lld\n", res);
}