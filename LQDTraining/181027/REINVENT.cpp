#include <bits/stdc++.h>
using namespace std;

#define task "REINVENT"

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

int n, m, x;
vector<int> adj[N];
int isSpe[N], source[N], dist[N], res;
queue<int> q;

int main() {
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i) dist[i] = oo;
	for (int i = 1; i <= x; ++ i) {
		int spe;
		scanf("%d", &spe);
		q.push(spe);
		dist[spe] = 0;
		source[spe] = spe;
		isSpe[spe] = 1;
	}
	res = n;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); ++ i) {
			int v = adj[u][i];
			if (source[u] != source[v]) res = min(res, dist[u] + 1 + dist[v]);
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				source[v] = source[u];
				q.push(v);
			}
		}
	}
	printf("%d", res);
}