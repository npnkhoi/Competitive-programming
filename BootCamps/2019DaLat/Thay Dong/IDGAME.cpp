#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int sh = 1e6;

int n, q;
int cnt[2 * N];
vector<int> query[2 * N];
long long ans[2 * N];

int main() {
	freopen("IDGAME.inp", "r", stdin);
	freopen("IDGAME.out", "w", stdout);
	scanf("%d%d", &n, &q);
	int val;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &val);
		val += sh;
		cnt[val] ++;
	}
	for (int i = 1; i <= q; ++ i) {
		scanf("%d", &val);
		if (val > 2e6) continue;
		query[val].push_back(i);
	}
	int l = 0, r = 2e6;
	long long ope = 0; // long long
	for (int i = 2e6; i >= 0; -- i) {
		if (i == 0 && query[i].empty()) break;
		while (1) {	
			while (cnt[l] == 0) l ++;
			while (cnt[r] == 0) r --;
			if (r - l <= i) break;
			int delta = min(cnt[l], cnt[r]);
			cnt[l] -= delta;
			cnt[l + 1] += delta;
			cnt[r] -= delta;
			cnt[r - 1] += delta;
			ope += delta;
			if (cnt[l] == 0) l ++;
			if (cnt[r] == 0) r --;
		}
		for (int x : query[i]) {
			ans[x] = ope;
		}
	}
	for (int i = 1; i <= q; ++i) {
		printf("%lld\n", ans[i]);
	}
}