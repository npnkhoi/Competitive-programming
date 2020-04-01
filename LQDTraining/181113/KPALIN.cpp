#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int K = 105;
const int L = 155;

int n, k, md;
char s[L];
int f[N][N][N][K], Exp[K];
vector<int> pre[K];

int main() {
	freopen("KPALIN.inp", "r", stdin);
	freopen("KPALIN.out", "w", stdout);
	scanf("%d%d%d", &n, &k, &md);
	scanf("%s", s + 1);

	for (int i = 0; i < k; ++ i) {
		pre[i * 10 % k].push_back(i);
		// cerr << i * 10 % k << " -> " << i << "\n";
	}
	Exp[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		Exp[i] = Exp[i - 1] * 10 % k;
	}

	for (int l = 0; l <= n + 1; ++ l) {
		for (int r = 0; r <= n + 1; ++ r) {
			f[0][l][r][0] = 1;
		}
	}
	for (int l = 1; l <= n; ++ l) {
		for (int r = l; r <= n; ++ r) {
			for (int rem = 0; rem < k; ++ rem) {
				f[1][l][r][rem] = f[1][l][r - 1][rem];
			}
			f[1][l][r][(s[r] - '0') % k] = (f[1][l][r][(s[r] - '0') % k] + 1) % md; 
		}
	}

	for (int d = 2; d <= n; ++ d) {
		for (int r = 1; r <= n; ++ r) {
			for (int l = r - 1; l >= 1; -- l) {
				// if (s[l] != s[r]) continue;
				for (int rem = 0; rem < k; ++ rem) {
					f[d][l][r][rem] = 
						(f[d][l + 1][r][rem] + f[d][l][r - 1][rem] - f[d][l + 1][r - 1][rem] + md) % md;
					if (s[l] == s[r]) {
						// cerr << "into " << d << " " << l << " " << r << "\n";
						int tmp = (rem - (s[l] - '0') * (Exp[d - 1] + 1) % k + k) % k;
						// cerr << tmp << "\n";
						for (int preRem : pre[tmp])
							f[d][l][r][rem] = (f[d][l][r][rem] + f[d - 2][l + 1][r - 1][preRem]) % md;
					}
				}
			}
		}
	}
	// for (int d = 0; d <= n; ++ d) {
	// 	for (int l = 1; l <= n; ++ l) {
	// 		for (int r = l; r <= n; ++ r) {
	// 			for (int rem = 0; rem < k; ++ rem) {
	// 				cerr << d << " " << l << " " << r << " " << rem << " " << f[d][l][r][rem] << "\n";					 
	// 			}
	// 		}
	// 	}
	// }
	int res = 0;
	for (int i = 1; i <= n; ++ i) res = (res + f[i][1][n][0]) % md;
	printf("%d", res);
}