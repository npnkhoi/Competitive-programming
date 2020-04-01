#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 5;

int s[N];

struct Node {
	int l, r;
	long long cnt;
	vector<ii> vl, vr;
	
	void combine(const Node &a, const Node &b) {
		// cerr << "into combine\n";
		int tmp;
		vl = a.vl;
		for (ii x : b.vl) {
			tmp = __gcd(vl.back().second, x.second);
			if (tmp == vl.back().second) 
				vl.back().first += x.first;
			else 
				vl.push_back(make_pair(x.first, tmp));
		}
		// cerr << "done1\n";
		vr = b.vr;
		for (ii x : a.vr) {
			tmp = __gcd(vr.back().second, x.second);
			if (tmp == vr.back().second)
				vr.back().first += x.first;
			else 
				vr.push_back(make_pair(x.first, tmp));
		}
		// cerr << "done2\n";
		cnt = a.cnt + b.cnt;
		// cerr << "intial cnt: " << cnt << "\n";
		s[0] = b.vl[0].first;
		for (int i = 1; i < b.vl.size(); ++ i) {
			s[i] = s[i - 1] + b.vl[i].first;
		}
		for (ii x : a.vr) {
			tmp += x.first;
			if (__gcd(x.second, b.vl[0].second) == 1) break;
			int lo = 0, hi = b.vl.size() - 1, mid, bs = lo;
			while (lo <= hi) {
				// cerr << lo << " " << hi << "\n"
				mid = (lo + hi) / 2;
				if (__gcd(x.second, b.vl[mid].second) != 1) {
					bs = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			cnt += 1LL * x.first * s[bs];
		}
		// cerr << "end combine\n";
	}
};


struct IntervalTree {
	vector<Node> IT;
	vector<int> idLeaf;
	void build(int a[], int p, int l, int r) {
		IT[p].l = l;
		IT[p].r = r;
		if (l == r) {
			IT[p].vl.resize(1);
			IT[p].vr.resize(1);
			IT[p].vl[0] = make_pair(1, a[l]);
			IT[p].vr[0] = make_pair(1, a[l]);
			IT[p].cnt = (a[l] > 1);
			idLeaf[l] = p;
			// cerr << l << " " << r << " " << a[l] << " " << IT[p].cnt << "\n";
			return;
		}
		int mid = (l + r) / 2;
		build(a, 2 * p, l, mid);
		build(a, 2 * p + 1, mid + 1, r);
		IT[p].combine(IT[2 * p], IT[2 * p + 1]);
		// cerr << l << " " << r << " " << IT[p].cnt << "\n";
		// for (ii x : IT[p].vl) cerr << x.first << " " << x.second << ", "; cerr << "\n";
		// for (ii x : IT[p].vr) cerr << x.first << " " << x.second << ", "; cerr << "\n";
	}
	void update(int idx, int val) {
		int p = idLeaf[idx];
		IT[p].vl[0] = make_pair(1, val);
		IT[p].vr[0] = make_pair(1, val);
		IT[p].cnt = (val != 1);
		while (1) {
			p = p / 2;
			if (p == 0) break;
			IT[p].combine(IT[2 * p], IT[2 * p + 1]);
		}
	}
	Node get(int p, int l, int r) {
		if (l <= IT[p].l && IT[p].r <= r) return IT[p];
		if (IT[2 * p].r < l) return get(2 * p + 1, l, r);
		if (r < IT[2 * p + 1].l) return get(2 * p, l, r);
		Node x = get(2 * p, l, r);
		Node y = get(2 * p + 1, l, r);
		Node z;
		z.combine(x, y);
		return z;
	}
	IntervalTree (int a[], int n) {
		IT.resize(4 * n + 5);
		idLeaf.resize(n + 5);
		build(a, 1, 1, n);
	}
};

int n, q, a[N];

int main() {
	freopen("sol.inp", "r", stdin);
	freopen("sol.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	IntervalTree IT(a, n);
	while (q --) {
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		if (type == 1) {
			IT.update(x, y);
		} else {
			Node res = IT.get(1, x, y);
			printf("%lld\n", res.cnt);
		}
	}
}