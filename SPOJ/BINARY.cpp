#include <bits/stdc++.h>
using namespace std;

string NumToString(long long n) {
	if (n == 0) {
		return "";
	} else return NumToString(n >> 1LL) + (char) (n % 2 + '0');
}

const int N = 34;

long long n, f[N][N];
int k;

int main() {
	while (scanf("%lld%d", &n, &k) != EOF) {
		memset(f, 0, sizeof f);
		n ++;
		string s = NumToString(n);
		int l = s.size();

		int cnt0 = 0;
		for (int i = 1; i <= l; ++i) {
			cnt0 += (s[i - 1] == '0');
			if (s[i - 1] == '1' && cnt0 < i - 1) f[i][cnt0 + 1] ++;
			if (i >= 2) f[i][0] ++;

			for (int j = 0; j <= l; ++j) {
				f[i + 1][j + 1] += f[i][j];
				f[i + 1][j] += f[i][j];
			}

		}
		printf("%lld\n", (k <= l ? (f[l][k] + (k == 1)) : 0));
	}
}