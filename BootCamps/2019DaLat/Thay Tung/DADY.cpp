#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;

int n, m, a, b, x, y, res;
char query;

struct Node {
	int l, r, val;
};

struct SegmentTree {
	vector<Node> a;
	void build(int p, int l, int r) {
		a[p].l = l;
		a[p].r = r;
		a[p].val = oo; // initial value
		if (l < r) {
			int mid = (l + r) / 2;
			build(2 * p, l, mid);
			build(2 * p + 1, mid + 1, r);
		}
	}
	void update(int p, int idx, int val) {
		if (a[p].l == a[p].r) {
			a[p].val = val;
		} else {
			if (idx <= (a[p].l + a[p].r) / 2)
				update(2 * p, idx, val);
			else update(2 * p + 1, idx, val);
			a[p].val = min(a[2 * p].val, a[2 * p + 1].val);
		}
	}
	// int getMin(int p, int l, int r) {
	// 	if (a[p].l > r || l > a[p].r) return oo; // -oo value
	// 	if (l <= a[p].l && a[p].r <= r) {
	// 		return a[p].val;
	// 	}
	// 	return min(getMin(get(2 * p, l, r), getMin(2 * p + 1, l, r)));
	// }
	void getAns(int p, int l, int r, int val) {
		if (res != -1) return;
		if (a[p].l > r || l > a[p].r) return; // -oo value
		if (a[p].val > val) return;

		if (l <= a[p].l && a[p].r <= r) {
			if (a[p].l == a[p].r) {
				res = a[p].l;
				return;
			}
		}
		getAns(2 * p, l, r, val);
		getAns(2 * p + 1, l, r, val);
	}
	SegmentTree (int n) {
		a.resize(4 * n + 1);
		build(1, 1, n);
	}
};


int main() {
	// freopen("DADY.inp", "r", stdin);
	// freopen("DADY.ans", "w", stdout);

	scanf("%d%d", &n, &m);

	SegmentTree IT(n);

	for (int i = 1; i <= m; ++ i) {
		scanf(" %c", &query);
		if (query == 'M') {
			scanf("%d%d", &x, &a);
			IT.update(1, a, x);
		} else {
			scanf("%d%d", &y, &b);	
			res = -1;
			IT.getAns(1, b, n, y);
			printf("%d\n", res);
		}
	}
}