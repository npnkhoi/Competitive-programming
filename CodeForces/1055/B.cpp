#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, l, mark[N], cnt;
long long a[N];

void update(int i) {
	mark[i] = 1;
	if (mark[i-1] == 0 && mark[i+1] == 0) cnt ++;
	else if (mark[i-1] && mark[i+1]) cnt --;
}

int main() {
	// freopen("B.inp", "r", stdin);
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; ++ i) 
		if (a[i] > l) update(i);

	int type, p, d;
	for (int i = 1; i <= m; ++ i) {
		scanf("%d", &type);
		if (type == 0) printf("%d\n", cnt);
		else {
			scanf("%d%d", &p, &d);
			if (a[p] <= l && a[p] + d > l) {
				update(p);
			}
			a[p] += d;
		}
	}
}