#pragma comment(linker, "/STACK: 2000000")
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N = 1e5 + 5;

int n, m, c[N], l[N], deg[N], par[N];
long long s[N], res;
vector<int> adj[N], sub[N];
queue<int> q;

int main() {
	// freopen("D:\\Download\\dispatching\\input\\input34.txt", "r", stdin);
	// freopen("log.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", &par[i], &c[i], &l[i]);
		if (par[i]) adj[par[i]].push_back(i), deg[par[i]] ++;
	}
	for (int i = 1; i <= n; ++ i) {
		if (deg[i] == 0) {
			q.push(i);
			// cerr << i << "\n";
		}
	}

	while (!q.empty()) {
		// cerr << q.size() << "\n";
		int u = q.front();
		q.pop();
		// cout << u << "\n";
		deg[par[u]] --;
		if (deg[par[u]] == 0) {
			q.push(par[u]);
		}
		// -------- process vtx u
		sub[u].push_back(c[u]);
		for (int v : adj[u]) {
			sub[u].insert(sub[u].end(), sub[v].begin(), sub[v].end());
			sub[v].clear();
		}
		sort(sub[u].begin(), sub[u].end());
		s[0] = sub[u][0];
		for (int i = 1; i < sub[u].size(); ++ i) {
			s[i] = s[i - 1] + sub[u][i];
			if (s[i] > m) {
				sub[u].resize(i);
				break;
			}
		}
		res = max(res, 1LL * l[u] * (upper_bound(s, s + sub[u].size(), m) - s));
	}
	printf("%lld\n", res);
	// cerr << "Time = " << clock() / 1000.0;
}