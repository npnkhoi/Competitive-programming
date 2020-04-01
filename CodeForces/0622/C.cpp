using namespace std;
#include <stdio.h>
#include <iostream>
const int N = 2e5 + 50;
int n, m;
int a[N], ITmin[4*N], ITmax[4*N];
int left(int p) { return p<<1; }
int right(int p) { return (p<<1) + 1; }
void build_min (int p, int l, int r) {
	if (l == r) ITmin[p] = l;
	else {
		int mid = (l + r) / 2;
		build_min(left(p), l, mid);
		build_min(right(p), mid + 1, r);
		int p1 = ITmin[left(p)], p2 = ITmin[right(p)];
		ITmin[p] = (a[p1] < a[p2]) ? p1 : p2;
	}
	//printf("min %d %d: %d\n", l, r, ITmin[p]);
}

void build_max (int p, int l, int r) {
	if (l == r) ITmax[p] = l;
	else {
		int mid = (l + r) / 2;
		build_max(left(p), l, mid);
		build_max(right(p), mid + 1, r);
		int p1 = ITmax[left(p)], p2 = ITmax[right(p)];
		ITmax[p] = (a[p1] > a[p2]) ? p1 : p2;
	}
	//printf("max %d %d: %d\n", l, r, ITmax[p]);
}

int rmin(int p, int l, int r, int L, int R) {
 	if (r < L || R < l || r < l) return -1;
 	if (L <= l && r <= R) return ITmin[p];
 	int mid = (l + r) / 2;
 	int p1 = rmin(left(p), l, mid, L, R);
 	int p2 = rmin(right(p), mid + 1, r, L, R);
 	if (p1 == -1) return p2;
 	if (p2 == -1) return p1;
 	return (a[p1] < a[p2]) ? p1 : p2;
}

int rmax(int p, int l, int r, int L, int R) {
 	if (r < L || R < l || r < l) return -1;
 	if (L <= l && r <= R) return ITmax[p];
 	int mid = (l + r) / 2;
 	int p1 = rmax(left(p), l, mid, L, R);
 	int p2 = rmax(right(p), mid + 1, r, L, R);
 	if (p1 == -1) return p2;
 	if (p2 == -1) return p1;
 	return (a[p1] > a[p2]) ? p1 : p2;
}

int main() {
    //freopen("test.inp","r",stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int  i = 1; i <= n; i++) scanf("%d", &a[i]);
	build_min(1, 1, n);
	//cout << endl;
	build_max(1, 1, n);
	while (m--) {
		int l, r, x, x1, x2;
		scanf("%d %d %d", &l, &r, &x);
		x1 = rmin(1, 1, n, l, r);
		x2 = rmax(1, 1, n, l, r);
		//cout << x1 << " "  << x2 << "\n";
		if (a[x1] != x) cout << x1 << endl;
		else if (a[x2] != x) cout << x2 << endl;
		else cout << -1 << endl;
	}
}
