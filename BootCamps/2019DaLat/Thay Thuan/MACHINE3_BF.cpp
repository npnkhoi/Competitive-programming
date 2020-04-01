#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int T = 3e6 + 5;
const int N = 1e6 + 5;
const int MAX_T = 3e6;
const int K = 5;

int n, k;
pair<int, int> a[N];

void read(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

int main() {
	freopen("MACHINE3.inp", "r", stdin);
	freopen("MACHINE3.ans", "w", stdout);
	// scanf("%d%d", &n, &k);
	read(n); read(k);
	for (int i = 1; i <= n; ++ i) {
		int l, r;
		// scanf("%d%d", &l, &r);
		read(l); read(r);		
		a[i] = make_pair(l, r);
	}
	sort(a + 1, a + n + 1);
	
	if (k == 1) {
		int res = 0;
		for (int i = 1; i <= n; ++ i) res = max(res, a[i].se - a[i].fi);
		printf("%d", res);
	} else if (k == 2) {
		int res = 0;
		for (int i = 1; i <= n - 1; ++ i) {
			for (int j = n; a[j].fi > a[i].se; -- j) {
				res = max(res, a[i].se - a[i].fi + a[j].se - a[j].fi);
			}
		}
		printf("%d", res);
	} else {
		int res = 0;
		for (int i = 1; i <= n - 2; ++ i) {
			for (int j = n; a[j].fi > a[i].se; --j) {
				for (int k = n; a[k].fi > a[j].se; --k) {
					res = max(res, a[i].se - a[i].fi + a[j].se - a[j].fi + a[k].se - a[k].fi);
				}
			}
		}	
		printf("%d", res);
	}
}