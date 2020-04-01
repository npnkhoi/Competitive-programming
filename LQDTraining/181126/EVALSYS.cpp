#include <bits/stdc++.h>
using namespace std;

const int N_PRI = 25;

struct IntervalTree {
	struct Node {
		int l, r, lazy;
		long long val;
		Node() {}
	};
	vector<Node> a;

	IntervalTree () {}

	void build(int p, int l, int r) {
		a[p].l = l;
		a[p].r = r;
		a[p].val = a[p].lazy = 0;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(2 * p, l, mid);
		build(2 * p + 1, mid + 1, r);
	}

	void init(int n) {
		a.resize(4 * n);
		build(1, 1, n);
	}

	void lazyDown(int p) {
		a[p].val += 1LL * a[p].lazy * (a[p].r - a[p].l + 1);
		if (a[p].l < a[p].r) {
			a[2 * p].lazy += a[p].lazy;
			a[2 * p + 1].lazy += a[p].lazy;
		}
		a[p].lazy = 0;
	}

	void update(int p, int l, int r, int val) {
		lazyDown(p);
		if (l <= a[p].l && a[p].r <= r) {
			a[p].lazy = val;
			lazyDown(p);
			// cerr << "end update here: " << p << " " << a[p].val << "\n";
			return;
		}
		if (a[2 * p].r < l) {
			lazyDown(2 * p);
			update(2 * p + 1, l, r, val);
		} else if (r < a[2 * p + 1].l) {
			lazyDown(2 * p + 1);			
			update(2 * p, l, r, val);
		} else {
			update(2 * p, l, r, val);
			update(2 * p + 1, l, r, val);
		}
		a[p].val = a[2 * p].val + a[2 * p + 1].val;
	}

	long long get(int p, int l, int r) {
		// cerr << "get " << p << " " << a[p].l << " " << a[p].r << "\n";
		lazyDown(p);
		if (l <= a[p].l && a[p].r <= r) {
			// cerr << "end here: " << l << " " << a[p].l << " " << a[p].r << " " << r << "\n";
			// cerr << "return: " << a[p].val << "\n";
			return a[p].val;
		}
		if (a[2 * p].r < l) {
			// cerr << "return right\n";
			return get(2 * p + 1, l, r);
		}
		if (r < a[2 * p + 1].l) {
			// cerr << "get left\n";;
			return get(2 * p, l, r);
		}
		// cerr << "tach ra: " << a[2*p].l << " " << a[2*p].r << " " << 
		// a[2*p+1].l << " " << a[2*p+1].r << "\n";
		return get(2 * p, l, r) + get(2 * p + 1, l, r);
	}
};

int n, m;
IntervalTree IT[N_PRI];
int id[100];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 
	29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

long long Exp(int a, long long x, int m) {
	// cerr << a << " " << x << " " << m << "\n";
	if (x == 0) return 1;
	long long res = 1;
	res = Exp(a, x / 2, m);
	res = res * res % m;
	if (x & 1) res = res * a % m;
	return res;
}

void init() {
	for (int i = 0; i < N_PRI; ++ i) {
		id[primes[i]] = i;
		IT[i].init(n);
	}
}

void show(IntervalTree &IT) {
	cerr << "show\n";
	for (int i = 1; i <= 4 * n; ++ i) {
		cerr << i << " " << IT.a[i].l << " " << IT.a[i].r << " " << IT.a[i].val << " " << IT.a[i].lazy << "\n";
	}
	cerr << "\n";
}

void solve() {
	for (int i = 1; i <= m; ++ i) {
		int type, x, y, z;
		scanf("%d %d %d %d", &type, &x, &y, &z);
		if (type == 0) {
			long long res = 1;
			for (int i = 0; i < N_PRI; ++ i) {
				// cerr << IT[i].get(1, x, y) << "\n";
				res = res * Exp(primes[i], IT[i].get(1, x, y), z) % z;
			}
			printf("%lld\n", res);
		} else {
			for (int i = 0; i < N_PRI; ++ i) {
				if (z % primes[i]) continue;
				int cnt = 0;
				do {
					z /= primes[i];
					cnt ++;
				} while (z % primes[i] == 0);
				// cerr << primes[i] << " " << cnt << "\n";
				IT[i].update(1, x, y, (type == 1 ? cnt : -cnt));
			}
			// show(IT[0]);
		}
	}
}

int main() {
	// freopen("evalsys.inp", "r", stdin);
	// freopen("evalsys.out", "w", stdout);
	scanf("%d%d", &n, &m);
	init();
	solve();
}