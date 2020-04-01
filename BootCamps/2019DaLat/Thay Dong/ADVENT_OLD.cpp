#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int N = 2005;

struct FenwickTree {
	vector<int> ft;
	int n;

	void update(int i, int val) {
		for (; i <= n; i += i&-i) ft[i] += val;
	}
	int get(int i) {
		int res = 0;
		for (; i; i -= i&-i) res += ft[i];
		return res;
	}
	FenwickTree(int x) {
		ft.assign(x + 5, 0);
		n = x;
	}
};

int n, d, res;
pair<int, int> a[N];
int b[N];

void input() {
	freopen("ADVENT.inp", "r", stdin);
	freopen("ADVENT.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	scanf("%d", &d);
}

int wholeLen(int i) {
	return a[i].first + a[i].second;
}

void solve() {
	FenwickTree ftSum(n), ftCount(n); 
	sort(a + 1, a + n + 1, [](ii x, ii y) {
		return x.first > y.first;
	});
	for (int i = 1; i <= n; ++ i) {
		ftSum.update(i, a[i].first);
		ftCount.update(i, 1);
	}

	for (int i = 1; i <= n; ++ i) {
		b[i] = i;
	}
	sort(b + 1, b + n + 1, [](int x, int y) {
		return wholeLen(x) < wholeLen(y);
	});

	// **********************************************
	int ptr = 1, base = 0;

	for (int s = d; s >= 0; -- s) {
		while (ptr <= n && s + wholeLen(b[ptr]) < d) {
			// cerr << "hi sinh " << b[ptr] << "\n";
			base += a[b[ptr]].first;
			ftSum.update(b[ptr], - a[b[ptr]].first);
			ftCount.update(b[ptr], -1);
			ptr ++;
		}
		int l = 0, r = n, mid, bs = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (base + ftSum.get(mid) >= s) {
				bs = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		res = max(res, n - (ptr - 1) - ftCount.get(bs));
	}
	printf("%d\n", res);
}

void solve2() {
	for (int s = d; s >= 0; -- s) {
		int base =  0;
		for (int i = 1; i <= n; ++ i) {
			if (s + a[i].first + a[i].seond >= d)
		}
	}
}

int main() {
	input();
	solve();
}