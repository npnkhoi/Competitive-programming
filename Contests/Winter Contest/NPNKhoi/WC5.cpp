#include <bits/stdc++.h>
using namespace std;

#define task "WC5"

const long long MAX_VAL = 1e6;
const int N = 5005;

int tc, n;
int a[N];
vector<int> l[N], r[N];
int cnt[MAX_VAL + 5];

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i <= n; i ++) {
			l[i].clear();
			r[i].clear();
		}
		for (int i = 1; i < n; ++ i) {
			for (int j = i + 1; j <= n; ++ j) {
				if (1LL * a[i] * a[j] <= MAX_VAL) {
					l[j].push_back(a[i] * a[j]);
					//cerr << a[i] * a[j] << " into left " << j << "\n";
				}
				if (a[j] % a[i] == 0) {
					r[i].push_back(a[j] / a[i]);

				}
			}
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < (int) l[i].size(); j ++) {
				cnt[l[i][j]] ++;
			}
		}
		long long res = 0;
		for (int i = n; i >= 1; -- i) {
			for (int j = 0; j < (int) l[i].size(); ++ j) {
				cnt[l[i][j]] --;
			}
			for (int j = 0; j < (int) r[i].size(); ++ j) {
				res += cnt[r[i][j]];
			}
		}
		printf("%lld\n", res);
	}
}