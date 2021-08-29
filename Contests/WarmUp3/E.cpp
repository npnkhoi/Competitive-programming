#include <bits/stdc++.h>
using namespace std;

#define task "E"

const int N = 5e4 + 5;
const int M = 151;

struct Node {
	int val, lazy, l, r;
};
typedef pair<int, int> ii;

int tc, n, m, q;
int primes[M], id[M];
Node IT[38][8*N];
vector<ii> factors[M];

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); ++ i) {
		if (n % i == 0) return false;
	}
	return true;
}

void init() {
	for (int i = 2; i <= 150; i ++) {
		if (prime(i)) {
			primes[++ m] = i;
			id[i] = m;
			// cerr << i << "\n";
		}
	}
	// cerr << "num of primes: " << m << "\n";
	for (int i = 1; i <= 150; i ++) {
		int tmp = i;
		// cerr << tmp << "\n";
		for (int j = 2; tmp > 1; j ++) {
			if (tmp % j == 0) {
				int cnt = 0;
				do {
					cnt ++;
					tmp /= j;
				} while (tmp % j == 0);
				factors[i].push_back(make_pair(j, cnt));
			}
		}
	}
}

void build(Node IT[], int p, int l, int r) {
	IT[p].val = IT[p].lazy = 0;
	IT[p].l = l;
	IT[p].r = r;
	if (l < r) {
		int mid = (l + r) / 2;
		build(IT, 2 * p, l, mid);
		build(IT, 2 * p + 1, mid + 1, r);
	}
}

void lazyDown(Node IT[], int p) {
	IT[2 * p].lazy += IT[p].lazy;
	IT[2 * p + 1].lazy += IT[p].lazy;
	IT[p].val += IT[p].lazy * (IT[p].r - IT[p].l + 1);
	IT[p].lazy = 0;
}

int get(Node IT[], int p, int l, int r) {
	lazyDown(IT, p);
	if (IT[p].l > r || l > IT[p].r) return 0;
	if (l <= IT[p].l && IT[p].r <= r) {
		return IT[p].val;
	}
	return get(IT, 2 * p, l, r) + get(IT, 2 * p + 1, l, r);
} 

void update(Node IT[], int p, int l, int r, int val) {
	lazyDown(IT, p);
	// print1f("update %d %d, delta = %d\n", l, r, val); 
	// printf("node %d: %d %d\", p, IT[p].l, IT[p].r);
	if (IT[p].l > r || l > IT[p].r) return;
	// printf("update %d %d, delta = %d\n", l, r, val); 
	if (l <= IT[p].l && IT[p].r <= r) {
		IT[p].lazy += val;
		lazyDown(IT, p);
	} else {
		update(IT, 2 * p, l, r, val);
		update(IT, 2 * p + 1, l, r, val);
		IT[p].val = IT[2 * p].val + IT[2 * p + 1].val;
 	}
} 

long long Pow(long long a, long long x, long long p) {
	if (x == 0) return 1;
	else {
		long long res = Pow(a, x / 2, p);
		res = (res * res) % p;
		if (x % 2) {
			res = (res * a) % p;
		}
		return res;
	}
}

void show() {
	cerr << "show: ";
	for (int i = 1; i <= n; i ++) {
		long long res = 1;
		for (int j = 1; j <= m; j ++) {
			res *= Pow(primes[j], get(IT[j], 1, i, i), 1e9 + 7);
		}
		cerr << res << " ";
	}
	cerr << "\n";
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	init();
	// for (int i = 1; i <= 150; i ++) {
	// 	for (ii t : factors[i]) {
	// 		printf("(%d, %d) ", t.first, t.second);
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << m << "\n";
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= m; ++ i) {
			build(IT[i], 1, 1, n);
		}
		while (q --) {
			int ask, l, r;
			long long p;
			scanf("%d%d%d%lld", &ask, &l, &r, &p);
			if (ask == 0) {
				long long res = 1;
				for (int i = 1; i <= m; ++ i) {
					int tmp;
					if (l <= r) {
						tmp = get(IT[i], 1, l, r);
					} else {
						tmp = get(IT[i], 1, l, n) + get(IT[i], 1, 1, r);
					}
					// if (tmp > 0) cerr << i << " " << tmp << "\n";
					res = (res * Pow(primes[i], tmp, p)) % p;
				}
				printf("%lld\n", res);
			} else if (ask == 1) {
				for (ii t : factors[p]) {
					// cerr << t.first << " " << t.second << "\n";
					if (l <= r) {
						update(IT[id[t.first]], 1, l, r, t.second);	
					} else {
						update(IT[id[t.first]], 1, l, n, t.second);	
						update(IT[id[t.first]], 1, 1, r, t.second);	
					}				
				}
			} else {
				for (ii t : factors[p]) {
					if (l <= r) {
						update(IT[id[t.first]], 1, l, r, - t.second);	
					} else {
						update(IT[id[t.first]], 1, l, n, - t.second);	
						update(IT[id[t.first]], 1, 1, r, - t.second);	
					}					
				}
			}
			// show();
		}
	}
} 