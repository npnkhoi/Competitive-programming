#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int n, m, a[N];

int main() {
	freopen("evalsys.inp", "r", stdin);
	freopen("evalsys.ans", "w", stdout);	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) a[i] = 1;
	for (int i = 1; i <= m; ++ i) {
		int type, x, y, z;
		scanf("%d%d%d%d", &type, &x, &y, &z);
		if (type == 0) {
			long long res = 1;
			for (int i = x; i <= y; ++ i) {
				res = res * a[i] % z;
			}
			printf("%lld\n", res);
		} else {
			for (int i = x; i <= y; ++ i) {
				if (type == 1) a[i] *= z;
				else a[i] /= z;
			}
		}
	}
}	