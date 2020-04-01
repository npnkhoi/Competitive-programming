#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;

int n, m, res, idx;
int num[N], low[N], art[N];
vector<int> adj[N];
stack<int> st; 

void dfs(int u, int par, bool isRoot) {
	num[u] = low[u] = ++idx;
	if (adj[u].empty()) {
		// bc.component with size 1
		res = max(res, 1);
		return;
	}
	st.push(u);

	int cntEdgeToPar = 0;
	for (int i = 0; i < (int) adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == par && cntEdgeToPar == 0) {
			cntEdgeToPar = 1;
			continue;
		}

		if (num[v] != 0) {
			low[u] = min(low[u], num[v]);
		} else {
			dfs(v, u, 0);
			low[u] = min(low[u], low[v]);

			if (isRoot || low[v] >= num[u]) {
				// printf("%d (%d)", u, v);
				int cnt = 1;
				while (1) {
					int tmp = st.top();
					st.pop();
					++cnt;
					if (tmp == v) break;
				}
				res = max(res, cnt);
				// cerr << "\n";
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (num[i] == 0) {
			// root = i;
			// cntSonOfRoot = 0;
			dfs(i, -1, 1);
		}
		res = max(res, (int) st.size());
		while (!st.empty()) {
			st.pop();
		}
	}
	// for (int i = 1; i <= n; ++ i) {
	// 	printf("vtx %d: num = %d, low = %d\n", i, num[i], low[i]);
	// }
	printf("%d\n", res);
}