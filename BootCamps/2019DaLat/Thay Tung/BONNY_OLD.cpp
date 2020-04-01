#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

char str[N];
int s[N][30], n, res;

bool check(int d) {
	for (int i = 2 * d; i <= n; i += d) {
		for (int ch = 0; ch < 26; ++ ch) {
			if (s[i][ch] - s[i - d][ch] != s[d][ch]) return 0;
		}
	}
	return 1;
}

int main() {
	freopen("BONNY.txt", "r", stdin);
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; ++ i) {
		for (int ch = 0; ch < 26; ++ ch) {
			s[i][ch] = s[i - 1][ch] + (str[i] == ch + 'a');
		}
	}
	for (int i = 1; i <= n; ++ i) {
		if (n % i == 0) {
			if (check(i)) res = max(res, n / i);
			if (check(n / i)) res = max(res, i);
		}
	}
	printf("%d\n", res);
	cerr << "Time = " << clock() / (double) 1000;
}