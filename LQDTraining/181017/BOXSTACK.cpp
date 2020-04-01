#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Box{
	int w, h, d;
};

int n;
Box box[N];
long long f[N], res;

bool cmp(Box a, Box b) {
	if (a.w != b.w) return a.w > b.w;
	else return a.d > b.d;
}

int main() {
	freopen("BOXSTACK.inp", "r", stdin);
	freopen("BOXSTACK.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", &box[i].h, &box[i].w, &box[i].d);
		if (box[i].w > box[i].d) {
			swap(box[i].w, box[i].d);
		}
	}
	sort(box + 1, box + n + 1, cmp);
	// for (int i = 1; i <= n; ++ i) {
	// 	cerr << box[i].h << " " << box[i].w << " " << box[i].d << "\n";
	// }
	for (int i = 1; i <= n; ++ i) {
		f[i] = 0;
		for (int j = 1; j < i; ++ j) {
			if (box[j].w >= box[i].w && box[j].d >= box[i].d) {
				f[i] = max(f[i], f[j]);
			}
		}
		f[i] += box[i].h;
		res = max(res, f[i]);
	}
	printf("%lld", res);
}