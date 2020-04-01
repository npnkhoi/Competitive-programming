`#include <bits/stdc++.h>
using namespace std;

const int N = 32;

int tc, a, b, c, m, n, memo[N][N][N][2];
string s;

string toString(int c) {
	if (c == 0) return "";
	else return toString(c / 2) + (char) (c % 2 + '0');
}

int dp(int pos, int cnt1, int cnt2, int rem) {
	// cerr << "dp " << pos << " " << cnt1 << " " << cnt2 << " " << rem << "\n";
	if (pos == 0) {
		return (cnt1 == 0 && cnt2 == 0 && rem == 0);
	}
	if (cnt1 < 0 || cnt2 < 0 || rem < 0) return 0;
	if (memo[pos][cnt1][cnt2][rem] != -1) return memo[pos][cnt1][cnt2][rem];

	int res = 0, tmp, newRem;

	tmp = s[pos - 1] - '0' - rem - 0;
	if (tmp < 0) {
		tmp += 2;
		newRem = 1;
	} else newRem = 0;
	res += dp(pos - 1, cnt1, cnt2 - (tmp == 1), newRem);

	tmp = s[pos - 1] - '0' - rem - 1;
	if (tmp < 0) {
		tmp += 2;
		newRem = 1;
	} else newRem = 0;
	res += dp(pos - 1, cnt1 - 1, cnt2 - (tmp == 1), newRem);	

	// cerr << "dp " << pos << " " << cnt1 << " " << cnt2 << " " << rem << " = " << res << "\n";

	return memo[pos][cnt1][cnt2][rem] = res;
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d", &a, &b, &c);
		m = __builtin_popcount(a);
		n = __builtin_popcount(b);
		s = toString(c);
		// cerr << m << " " << n << " " << s << "\n";
		memset(memo, -1, sizeof memo);
		printf("%d\n", dp(s.size(), m, n, 0));
	}
}