#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string s;
int f[N][2][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc; cin >> tc;
	while (tc --) {
		cin >> s;
		int n = s.size();

		if (n == 1) {
			cout << "0\n";
			continue;
		}

		f[1][0][0] = (s[0] == s[1] ? N : 0);
		f[1][0][1] = f[1][1][0] = 1;
		f[1][1][1] = 2;
		for (int i = 2; i < n; ++ i) {
			if (s[i] == s[i - 1]) {
				f[i][0][0] = N;
			} else {
				if (s[i] == s[i - 2]) {
					f[i][0][0] = f[i - 1][1][0];
				} else {
					f[i][0][0] = min(f[i - 1][1][0], f[i - 1][0][0]);
				}
			}

			f[i][0][1] = 1 + min(f[i - 1][0][0], f[i - 1][1][0]);
			if (s[i] == s[i - 2]) {
				f[i][1][0] = f[i - 1][1][1];
			} else {
				f[i][1][0] = min(f[i - 1][0][1], f[i - 1][1][1]);
			}
			f[i][1][1] = 1 + min(f[i - 1][0][1], f[i - 1][1][1]);
		}

		cout << min(min(f[n - 1][0][0], f[n - 1][0][1]),min(f[n - 1][1][0], f[n - 1][1][1])) << '\n';
	}
} 