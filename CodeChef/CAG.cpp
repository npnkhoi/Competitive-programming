#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
long long k;
int mark[N], cnt, res;
vector<int> adj[N];

void dfs(int u) {
	mark[u] = 1;
	++ cnt;
	for (int v : adj[u]) {
		if (!mark[v]) {
			dfs(v);
		}
	}
} 

int main() {
	scanf("%d %d %lld", &n, &m, &k);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	res = n;
	for (int i = 1; i <= n; ++ i) {
		cnt = 0;
		memset(mark, 0, sizeof mark);
		dfs(i);
		res = min(res, cnt);
	}
	printf("%lld", k * res);
}