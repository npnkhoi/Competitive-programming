#include <bits/stdc++.h>
using namespace std;

#define task "SINHVIEN"

const int N = 1e6 + 5;
const int M = 105;
const int K = 505;
const long long oo = 1e18;

int n, m, k;
int cnt[M];
long long f[M][K];

long long noise(int cnt, int groups) {
	if (cnt % groups == 0) {	
		return 1LL * (cnt / groups) * (cnt / groups + 1) / 2 * groups;
	} else {
		int cnt1 = cnt / groups;
		int groups1 = groups - cnt % groups;
		return 1LL * cnt1 * (cnt1 + 1) / 2 * groups1 + 1LL * (cnt1 + 1) * (cnt1 + 2) / 2 * (groups - groups1); 
	}
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int room;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &room);
		cnt[room] ++;
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j <= k; j ++) {
			f[i][j] = oo;
			for (int ban = 0; ban <= j; ban ++) {
				f[i][j] = min(f[i][j], f[i-1][j - ban] + noise(cnt[i], ban + 1));
				//cerr << i << " " << j << " " << f[i][j] << "\n";
			}
		}
	}
	printf("%lld\n", f[m][k]);
}