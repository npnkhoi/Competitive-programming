#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
ii edgeList[] = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int u, val, v;
		scanf("%d", &u, &val, &v);
		u --; v --;
		if (u > v) swap(u, v);

		minVal[u][v] = min(minVal[u][v], val);
		sum[u][v] += val;
		++ cnt[u][v];
	}
	
	for (int mask = 1; mask < (1 << 4); ++ mask) {
		for (int mask2 = 0; mask2 < (1 << 6); ++ mask2) {
			// check
			if (__builtin_popcount(mask) > 1) {
				memset(deg, 0, sizeof deg);
				for (int i = 0; i < 6; ++ i) {
					int u = edgeList[i].fi, v = edgeList[i].se;
					int tmp = (mask2 & (1 << i)) > 0;
					if (mask & (1 << u)) deg[u] += cnt[u][v] - tmp;
					if (mask & (1 << v)) deg[v] += cnt[u][v] - tmp;
				}
				int tmp = 0;
				for (int u = 0; u < 4; ++ u) {
					tmp += deg[u] % 2;
				}
				if (tmp == 1 || tmp == 3) continue;
			}
		}
	}
}