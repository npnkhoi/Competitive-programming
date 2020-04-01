#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int oo = 1e9 + 7;
const int K = 55;

int n, k;
int a[N], f[N][K];

int main() {
	scanf("%d%d", &n, &k);
	for (int r = 1; r < k; r ++) f[0][r] = -oo;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		for (int rem = 0; rem < k; rem ++) {
			f[i][rem] = max(f[i-1][rem], 1 + f[i-1][(rem - a[i] % k + k) % k]);
		}
	}
	if (f[n][0] == oo) printf("0");
	else printf("%d", f[n][0]);
}