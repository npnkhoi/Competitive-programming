#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const long long md = 1e9 + 7;

int tc, n;
int a[N], cnt[2 * N];
long long comb[N][N], Exp2[N];

int main() {
	comb[0][0] = 1;
	for (int i = 1; i <= 1000; ++ i) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j <= i - 1; ++ j) {
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % md;
		}
	}

	Exp2[0] = 1;
	for (int i = 1; i <= 1000; ++ i) 
		Exp2[i] = Exp2[i - 1] * 2 % md;
	// ----------------------------------------------------
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
			cnt[a[i]] ++;
		}
		long long res = (Exp2[n] - 1 + md) % md;
		for (int i = 1; i <= 2 * n; ++ i) {
			cnt[i] = cnt[i - 1] + cnt[i];
			if (cnt[i] == cnt[i - 1]) continue;
			
			long long tmp = 0;
			for (int z = 1; z <= cnt[i] && z <= n - cnt[i]; ++ z) {
				tmp = (tmp + (comb[cnt[i]][z] - comb[cnt[i - 1]][z]) * comb[n - cnt[i]][z] % md) % md;
			}
			res = (res - tmp + md) % md;
		}
		printf("%lld\n", res);
	}
}