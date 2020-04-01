#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define fi first
#define se second
#define mp make_pair

const int N = (1 << 18) + 5;

int n, a[N], id[5], res;
ii maxx[N];

ii operator + (ii x, ii y) {
	id[1] = x.fi;
	id[2] = x.se;
	id[3] = y.fi;
	id[4] = y.se;
	sort(id + 1, id + 5, [](int u, int v){
		// if (v == -1) return true;
		// if (u == -1) return false;
		return a[u] > a[v];
	});
	if (id[1] != id[2]) return mp(id[1], id[2]);
	else if (id[1] != id[3]) return mp(id[1], id[3]);
	else return mp(id[1], id[4]);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < (1 << n); i ++) {
		scanf("%d", &a[i]);
		maxx[i] = mp(i, 0);
		for (int j = 0; j < 18; ++ j) {
			if ((i & (1 << j)) > 0) {
				maxx[i] = maxx[i] + maxx[i ^ (1 << j)];
			}
		}
		if (i > 0) {
			res = max(res, a[maxx[i].fi] + a[maxx[i].se]);
			printf("%d\n", res);
		}
	}
}