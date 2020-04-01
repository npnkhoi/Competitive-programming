#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAX_VAL = 1e3;

int n, a[N];
long long cnt[MAX_VAL + 5], res;

int main() {
	freopen("BTRI.inp", "r", stdin);
	freopen("BTRI.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		cnt[a[i]] ++;
	}
	for (int i = 1; i <= MAX_VAL; ++ i) {
		if (2 * i <= MAX_VAL) {
			res += cnt[i] * (cnt[i] - 1) / 2 * cnt[2 * i];
		}
		for (int j = i + 1; j <= MAX_VAL; ++ j) {
			if (i + j <= MAX_VAL)
				res += cnt[i] * cnt[j] * cnt[i + j];
		}
	}
	// cerr << res << "\n";
	if (cnt[0] >= 3) res += cnt[0] * (cnt[0] - 1) * (cnt[0] - 2) / 6;
	for (int i = 1; i <= MAX_VAL; ++ i) 
		if (cnt[i] >= 2) res += cnt[0] * cnt[i] * (cnt[i] - 1) / 2;
	printf("%lld", res);
}