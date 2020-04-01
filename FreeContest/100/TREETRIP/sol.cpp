#include <bits/stdc++.h>
using namespace std;

const int N = 20, MASK = (1 << 16) + 5;
const long long oo = 1e18;

int n, A, B;
int a[N][N];
long long dp[MASK][N], res;

long long cost(int x) {
	if (x != 0) return min((long long) A * x, (long long) B);
	else return B;
}

int main() {
	scanf("%d %d %d", &n, &A, &B);
	for (int i = 1; i < n; ++ i) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		a[u][v] = a[v][u] = c;
	}
	for (int mask = 0; mask < (1 << n); ++ mask) {
		for (int v = 0; v < n; ++ v) {
			dp[mask][v] = oo;
		}
	}
	dp[1][0] = 0;
	for (int mask = 2; mask < (1 << n); ++ mask) {
		for (int v = 0; v < n; ++ v) {
			if ((mask >> v & 1) == 0) continue;
			for (int u = 0; u < n; ++ u) {
				if ((mask >> u & 1) == 0 || u == v) continue;
				dp[mask][v] = min(dp[mask][v], dp[mask ^ (1 << v)][u] + cost(a[u + 1][v + 1]));
			}
		}
	}
	res = oo;
	for (int u = 1; u < n; ++ u) 
		res = min(res, dp[(1 << n) - 1][u] + cost(a[u + 1][1]));
	printf("%lld\n", res);
}