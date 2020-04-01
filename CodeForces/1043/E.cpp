#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m, x[N], y[N];
pair<int, int> diff[N];
long long score[N], sx[N], sy[N];

long long sum(long long s[], int l, int r) {
	return s[r] - s[l-1];
} 

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &x[i], &y[i]);
		diff[i] = make_pair(x[i] - y[i], i);
	}
	sort(diff + 1, diff + n + 1);
	for (int i = 1; i <= n; ++ i) {
		// cerr << diff[i].second << "\n";
		sx[i] = sx[i-1] + x[diff[i].second];
		sy[i] = sy[i-1] + y[diff[i].second];
	}
	for (int i = 1; i <= n; ++ i) {
		int idx = diff[i].second;
		score[idx] = 1LL * (i - 1) * y[idx] + 1LL * (n - i) * x[idx] 
			+ sum(sx, 1, i-1) + sum(sy, i+1, n);
	}
	// for (int i = 1; i <= n; ++ i) {
	// 	printf("%lld ", score[i]);
	// }
	// cerr << "\n";
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		long long tmp = min(x[u] + y[v], x[v] + y[u]);
		score[u] -= tmp;
		score[v] -= tmp;
	}
	for (int i = 1; i <= n; ++ i) {
		printf("%lld ", score[i]);
	}
}