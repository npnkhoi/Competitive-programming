#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, p, cnt, sum;
int mark[N];
vector<int> adj[N];

void dfs(int u) {
	// cerr << "dfs " << u << "\n";
	mark[u] = 1;
	cnt ++;
	for (int v : adj[u]) {
		if (mark[v]) continue;
		dfs(v);
	}
}

int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= p; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		u ++; v ++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long res = 0;
	for (int i = 1; i <= n; ++ i) {
		if (!mark[i]) {
			cnt = 0;
			dfs(i);
			// cerr << i << " " << cnt << "\n";
			res += 1LL * cnt * sum;
			sum += cnt;
		}
	}
	printf("%lld\n", res);
}