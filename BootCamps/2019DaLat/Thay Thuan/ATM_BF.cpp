#include <bits/stdc++.h>
using namespace std;

const int NUM = 1e6 + 5, C = 16 * 4, oo = 1e9 + 7;
const vector<int> types = {1, 2, 3, 5};

vector<int> v;
int tc, c, f[C][NUM], cnt[C][NUM];
long long num;

int main() {
	freopen("ATM.inp", "r", stdin);
	freopen("ATM.ans", "w", stdout) ;
	scanf("%d", &tc);
 	while (tc --) {
		scanf("%lld %d", &num, &c);
		if (num % 1000 != 0) {
			printf("0\n");
		}
		num /= 1000;
		v.clear();
		int tmp = 1;
		for (int i = 0; i <= c; ++ i) {
			for (int j : types) {
				v.push_back(j * tmp);
			}
			tmp *= 10;
		}
		// cerr << "types: \n";
		// for (int x : v) cerr << x << "\n";
		// ---------------------------------------------
		for (int j = 1; j <= num; ++ j) f[0][j] = oo;
		for (int i = 0; i <= v.size(); ++ i) cnt[i][0] = 1;

			// cerr << "f[1][0]: " << f[1][0] << '\n';

		for (int i = 1; i <= v.size(); ++ i) {
			for (int j = 1; j <= num; ++ j) {
				f[i][j] = f[i-1][j];
				cnt[i][j] = cnt[i-1][j];
				// cerr << i << " " << j << " " << v[i - 1] << "\n";
				if (j >= v[i - 1]) {
					// cerr << "here1" << i << " " << j - v[i-1] << "\n"; 
					// cerr << f[i][j] << " " << f[i][j - v[i-1]] + 1 << "\n";
					if (f[i][j] > f[i][j - v[i - 1]] + 1) {
						f[i][j] = f[i][j - v[i  - 1]] + 1;
						cnt[i][j] = cnt[i][j - v[i - 1]]; 
						// cerr << "here" << i << " " << j - v[i - 1] << "\n";
					} else if (f[i][j] == f[i][j - v[i - 1]] + 1) {
						cnt[i][j] += cnt[i][j - v[i - 1]];
					}
				}
				// cerr << i << " " << j << " " << f[i][j] << " " << cnt[i][j] << "\n";
			}
		}
		printf("%d %d\n", f[v.size()][num], cnt[v.size()][num]);
	}
}