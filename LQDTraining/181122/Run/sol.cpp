#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int md = 1e9 + 7;
const int oo = 1e9 + 7;

int n, m, res;
int c[N][N], trace[N];
queue<int> q;
vector<int> adj[N];

bool BFS() {
	memset(trace, 0, sizeof trace);
	trace[1] = -1;
	while (!q.empty()) q.pop();
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (c[u][v] <= 0 || trace[v] != 0) continue;
			trace[v] = u;
			if (v == n) return 1;
			q.push(v);
		}
	}
	return 0;
}

void augment() {
	int u = n, minEdge = oo;
	while (1) {
		if (u == 1) break;
		minEdge = min(minEdge, c[trace[u]][u]);
		u = trace[u];
	}
	res = (res + minEdge) % md;
	u = n;
	while (1) {
		if (u == 1) break;
		c[trace[u]][u] -= minEdge;
		c[u][trace[u]] += minEdge;
		u = trace[u];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	long long tmp = 1;
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		u ++; v ++;
		adj[u].push_back(v);		
		adj[v].push_back(u);
		c[u][v] = tmp;
		tmp = tmp * 3 % md;
	}
	while (BFS()) augment();
	printf("%d\n", res);
}