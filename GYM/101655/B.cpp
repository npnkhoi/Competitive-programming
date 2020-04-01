#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const long long oo = 1e18 + 7;

int n, m, k;
long long d[N][N];
queue<int> q;
int mark[N];

bool ok(long long x) {
	for (int s = 1; s <= n; ++ s) {
		memset(mark, 0, sizeof mark);
		while (!q.empty()) q.pop();

		q.push(s); mark[s] = 1;
		int cnt = 1;

		for (int i = 1; i <= k; ++ i) {
			int t = q.size();
			while (t --) {
				int u = q.front(); q.pop();
				for (int v = 1; v <= n; ++ v) {
					if (d[u][v] <= x && mark[v] == 0) {
						mark[v] = 1;
						q.push(v);
						cnt ++;
					}
				}
			}
		}
		if (cnt < n) return false;
	}
	return true;
}

int main() {
	// freopen("test.inp", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = (i == j ? 0 : oo);
			}
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			long long c;
			scanf("%d%d%lld", &u, &v, &c);
			u ++, v ++;
			d[v][u] = d[u][v] = c;
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++ j) {
				for (int k = 1; k <= n; ++ k) {
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
				}
			}
		}

		long long l = 0, r = 1e11, bs = r;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (ok(mid)) {
				bs = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		printf("%lld\n", bs);
	}
}