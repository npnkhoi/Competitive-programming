#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 1e3 + 5;
const int oo = 1e9 + 7;

int tc, n, m, iTest, w[N], v[N];
int f[N][M], state[N][M];
vector<int> ans;

int dp(int i, int j) {
	if (j < 0) return - oo;
	if (i == 0) return 0;
	if (state[i][j] == iTest) {
		return f[i][j];
	}

	state[i][j] = iTest;
	return f[i][j] = max(dp(i - 1, j), dp(i - 1, j - w[i]) + v[i]);
}

void trace(int i, int j) {
	if (i == 0) return;
	if (dp(i, j) == dp(i - 1, j)) {
		trace(i - 1, j);
	} else {
		ans.push_back(i);
		trace(i - 1, j - w[i]);
	}
}

int main() {
	scanf("%d", &tc);
	for (iTest = 1; iTest <= tc; ++ iTest) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &w[i]);
		}
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &v[i]);
		}
		printf("%d ", dp(n, m));
		ans.clear();
		trace(n, m);
		printf("%d\n", (int) ans.size());
		for (int v : ans) {
			printf("%d ", v);
		}
		printf("\n");
 	}
}