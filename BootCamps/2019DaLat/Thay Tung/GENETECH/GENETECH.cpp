#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

typedef pair<int, int> ii;

int n, q, a[N], ans[N], IT[4 * N];
char ch;
vector<int> st;
vector<ii> query[N];

struct Node {
	int l, r, sum, minSuf;
};

void combine(Node a, Node b, Node &c) {
	// a + b = c
	c.sum = a.sum + b.sum;
	c.minSuf = min(b.minSuf, a.minSuf + b.sum);
}

struct SegmentTree {
	vector<Node> a;
	void build(int p, int l, int r) {
		a[p].l = l;
		a[p].r = r;
		a[p].sum = 0; // initial value
		a[p].minSuf = 0;
		if (l < r) {
			int mid = (l + r) / 2;
			build(2 * p, l, mid);
			build(2 * p + 1, mid + 1, r);
			combine(a[2*p], a[2*p + 1], a[p]);
		}
	}
	void update(int p, int idx, int val) {
		if (a[p].l == a[p].r) {
			a[p].sum = val;
			a[p].minSuf = min(val, 0);
		} else {
			if (idx <= (a[p].l + a[p].r) / 2)
				update(2 * p, idx, val);
			else update(2 * p + 1, idx, val);
			combine(a[2 * p], a[2 * p + 1], a[p]);
		}
	}

	Node get(int p, int l, int r) {
		// cerr << "get " << p << "\n";
		// if (a[p].l > r || l > a[p].r) return - (1e9 + 7); // -oo value
		// mustn't go outside !!!!
		if (l <= a[p].l && a[p].r <= r) {
			return a[p];
		}
		if (a[2 * p].r < l) return get(2 * p + 1, l, r);
		else if (r < a[2 * p + 1].l) return get(2 * p, l, r);
		else {
			Node tmp;
			combine(get(2 * p, l, r), get(2 * p + 1, l, r), tmp);
			return tmp;
		}
	}
	SegmentTree (int n) {
		a.resize(4 * n + 1);
		build(1, 1, n);
	}
};

int main() {
	scanf("%d", &n);
	SegmentTree ST(n);
	for (int i = 1; i <= n; ++ i) {
		scanf(" %c", &ch);
		a[i] = (ch == 'C' ? 1 : -1);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		query[l].push_back(make_pair(r, i));
	}
	for (int i = n; i; --i) {
		if (a[i] == -1) {
			st.push_back(i);
			// ST.update(1, i, 0);
		} else {
			ST.update(1, i, 1);
			if (!st.empty()) {
				ST.update(1, st.back(), -1);
				st.pop_back();
			}
		}
		for (ii j : query[i]) {
			// cerr << "query\n";
			int l = i, r = j.first;
			// cerr << l << " " << r << "\n";
			ans[j.second] = upper_bound(st.rbegin(), st.rend(), r) - st.rbegin() - ST.get(1, l, r).minSuf;
			// cerr << "ok\n";
		}
	}
	for (int i = 1; i <= q; ++ i) 
		printf("%d\n", ans[i]);
}