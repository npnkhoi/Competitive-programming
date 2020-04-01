#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 1e5 + 5;
const long long md = 1e9 + 7;
const int base1 = 26;
const int base2 = 37;

typedef pair<long long, long long> pll;

int n, m, a[N], b[N], head;
map<int, int> id;
pll Exp[N], h[N];
vector<int> query[N], pos[N];

pll getHash(int l, int r) {
	return make_pair(
		(h[r].fi - h[l - 1].fi * Exp[r - l + 1].fi + md * md) % md,
		(h[r].se - h[l - 1].se * Exp[r - l + 1].se + md * md) % md);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		if (id.find(a[i]) == id.end()) {
			id[a[i]] = ++ m;
			// head[i] = 1;
		}
		b[i] = a[i];
		a[i] = id[a[i]];
		// pos[a[i]].push_back(i);
	}
	// hash init
	Exp[0] = make_pair(1, 1);
	for (int i = 1; i <= n; ++ i) {
		Exp[i].fi = Exp[i - 1].fi * base1 % md;
		Exp[i].se = Exp[i - 1].se * base2 % md;
	}
	// build hash
	for (int i = 1; i <= n; ++ i) {
		h[i].fi = (h[i - 1].fi * base1 + a[i]) % md;
		h[i].se = (h[i - 1].se * base2 + a[i]) % md;
	}
	// main
	for (int i = 1; i <= n; ++ i) {
		for (int j : pos[a[i]]) {
			query[i - j].push_back(i);
		}
		pos[a[i]].push_back(i);
	}
	head = 1;
	for (int l = 1; l <= n / 2; ++ l) {
		for (int y : query[l]) {
			int x = y - l;
			// cerr << "check " << x << " " << y << " " << l << "\n";
			// cerr << getHash(x, x + l - 1).fi << " " << getHash(x, x + l - 1).se << "\n";
			// cerr << getHash(y, y + l - 1).fi << " " << getHash(y, y + l - 1).se << "\n";
 			if (x >= head && getHash(x, x + l - 1) == getHash(y, y + l - 1)) {
				head = y;
			}
			// cerr << "head = " << head << "\n";
		}
	}
	printf("%d\n", n - head + 1);
	for (int i = head; i <= n; ++ i) {
		printf("%d ", b[i]);
	}
}