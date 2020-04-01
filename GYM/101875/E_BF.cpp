#include <bits/stdc++.h>
using namespace std;

const int N = 455;
const int oo = 1e9 + 7;

char s[N];
int l, k;

int main() {
	freopen("E.inp", "r", stdin);
	freopen("E.ans", "w", stdout);
	scanf("%d%d %s", &l, &k, s);
	int res = l;
	for (int mask = 0; mask < (1 << l); ++ mask) {
		int cnt = 0, sum = 0, tmp = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] == '1' && (mask & (1 << i))) {
				cnt ++;
				sum += cnt;
			} else {
				if (s[i] == '1' && !(mask & (1 << i))) {
					tmp ++;
				}
				cnt = 0;
			}
		}
		if (sum <= k) res = min(res, tmp);
	}
	printf("%d", res);
}