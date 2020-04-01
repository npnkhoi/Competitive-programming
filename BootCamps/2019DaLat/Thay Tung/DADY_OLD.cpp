#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;

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
	int get(int p, int l, int r) {
		if (a[p].l > r || l > a[p].r) return oo; // -oo value
		if (l <= a[p].l && a[p].r <= r) {
			return a[p].val;
		}
		return min(get(2 * p, l, r), get(2 * p + 1, l, r));
	}
	// functions for users
	SegmentTree (int n) {
		a.resize(4 * n + 1);
		build(1, 1, n);
	}
	void update(int idx, int val) {
		update(1, idx, val);
	}
	int get(int l, int r) {
		return get(1, l, r);
	}
};

int n, m, a, b, x, y;
char query;

int main() {
	freopen("DADY.inp", "r", stdin);
	freopen("DADY.ans", "w", stdout);

	scanf("%d%d", &n, &m);

	SegmentTree IT(n);

	for (int i = 1; i <= m; ++ i) {
		scanf(" %c", &query);
		if (query == 'M') {
			scanf("%d%d", &x, &a);
			IT.update(a, x);
		} else {
			scanf("%d%d", &y, &b);	
			if (IT.get(b, n) > y) {
				printf("-1\n");
			} else {
				int l = b, r = n, mid, bs = n;
				while (l <= r) {
					mid = (l + r) >> 1;
					if (IT.get(b, mid) <= y) {
						bs = mid;
						r = mid - 1;
					} else {
						l = mid + 1;
					}
				}
				printf("%d\n", bs);
			}
		}
	}
}