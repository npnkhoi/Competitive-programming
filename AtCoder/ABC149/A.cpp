#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int hand[] = {'r', 's', 'p'};
int n, k, r, s, p;
int dp[N][3];
string t;

int result(char x, char y) {
	if (x == 'r' && y == 's') return r;
	if (x == 's' && y == 'p') return s;
	if (x == 'p' && y == 'r') return p;
	return 0;
}

int main() {
	cin >> n >> k >> r >> s >> p >> t;
	for (int i = 0; i < n; ++i) { 
		if (i < k) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] = result(hand[j], t[i]);
			}
		} else {
			for (int j = 0; j < 3; ++ j) {
				for (int l = 0; l < 3; ++ l) {
					if (j == l) continue;
					dp[i][j] = max(dp[i][j], dp[i - k][l] + result(hand[j], t[i]));
				}
			}
		}
	}
	int res = 0;
	for (int i = n - 1; i > n - k - 1; --i) {
		res += max(dp[i][0], max(dp[i][1], dp[i][2]));
	}
	cout << res;
}