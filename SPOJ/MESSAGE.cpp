#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 805;
const int M = N * (N - 1);
int n, m;
int counterVtx, counterSCC;
int num[N], low[N], id[N], onStack[N];
stack<int> st;
vector<int> adj[N];
ii edge[M];
int degIn[N];


void tarjan(int u) {
	num[u] = low[u] = ++counterVtx;
	// id[u] = counterSCC;
	st.push(u);
	onStack[u] = 1;

	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		if (num[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (onStack[v]) {
			low[u] = min(low[u], num[v]);
		}
	}

	if (num[u] == low[u]) {
		++counterSCC;
		while (1) {
			int v = st.top();
			st.pop();
			onStack[v] = 0;
			id[v] = counterSCC;
			if (v == u) break;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		// cerr << i << " " << m << "\n";
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		edge[i] = make_pair(u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (num[i] == 0) {
			// ++counterSCC;
			tarjan(i);
		}
	}
	// cerr << counterSCC << "\n";
	for (int i = 1; i <= m; ++i) {
		if (id[edge[i].first] != id[edge[i].second])
			degIn[id[edge[i].second]] ++;
	}
	int res = 0;
	for (int i = 1; i <= counterSCC; ++i) {
		res += degIn[i] == 0;
	}
	printf("%d\n", res);
}