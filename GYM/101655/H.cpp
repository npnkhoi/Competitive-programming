#include <bits/stdc++.h>
using namespace std;

const int MAX_DIG = 18;

long long Exp[MAX_DIG + 2];


void backTrack(int l, int r, long long sum, long long ways, unordered_map<long long, int> &cnt) {
	if (l > r) {
		cnt[sum] += ways;
		return;
	}
	for (int d = 0; d <= 18; ++ d) { // sum of to digits that match each other
		backTrack(l + 1, r, sum + d * Exp[l], ways * d, cnt);
	}
}
 
void calc(int d) {
	int m = (d + 1) / 2;
	for (int i = 0; i < m; ++ i) {
		coef[i] = Exp[i] + Exp[d - 1 - i];
	}
	backTrack(0, m / 2 - 1, 0, 1, cnt1[d]);
	backTrack(m / 2, m - 1, 0, 1, cnt2[d]);
}

int countDigit(long long n) {
	if (n == 0) return 0;
	else return 1 + countDigit(n / 10);
}

int main() {
	Exp[0] = 1;
	for (int i = 1; i <= MAX_DIG; ++ i) {
		Exp[i] = Exp[i - 1] * 10;
	}
	for (int d = 1; d <= 18; ++ i) {
		calc(d);
	}

	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		int d = countDigit(n);
		long long res = 0;
		for (unordered_map<long long, int> :: iterator it = cnt1[d].begin(); it != cnt1[d].end(); ++ it) {
			if (it -> first <= n) {
				res += 1LL * it -> second * cnt2[n - it -> first];
			}
		}
		printf("%lld\n", res);
	}
}