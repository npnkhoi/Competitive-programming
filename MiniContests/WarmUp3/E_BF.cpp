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
int a[38][N];
vector<ii> factors[M];

long long sum(int a[], int l, int r) {
	long long res = 0;
	for (int i = l; i <= r; ++ i) {
		res += a[i];
	}
	return res;
}

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
		}
	}
	for (int i = 1; i <= 150; i ++) {
		int tmp = i;
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

int get(int a[], int l, int r) {
	int res = 0;
	for (int i = l; i <= r; ++ i) {
		res += a[i];
	}
	return res;
}

void update(int a[], int l, int r, int val) {
	for (int i = l; i <= r; ++ i) {
		a[i] += val;
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

int main() {
	// freopen(task".inp", "r", stdin);
	// freopen(task".ans", "w", stdout);
	init();
	scanf("%d", &tc);
	while (tc --) {
		memset(a, 0, sizeof a);
		scanf("%d%d", &n, &q);
		while (q --) {
			int ask, l, r, p;
			scanf("%d%d%d%d", &ask, &l, &r, &p);
			if (ask == 0) {
				long long res = 1;
				for (int i = 1; i <= m; ++ i) {
					int tmp;
					if (l <= r) {
						tmp = sum(a[i], l, r);
					} else {
						tmp = sum(a[i], l, n) + sum(a[i], 1, r);
					}
					res = (res * Pow(primes[i], tmp, p)) % p;
				}
				printf("%lld\n", res);
			} else if (ask == 1) {
				for (ii t : factors[p]) {
					if (l <= r) {
						update(a[id[t.first]], l, r, t.second);	
					} else {
						update(a[id[t.first]], l, n, t.second);	
						update(a[id[t.first]], 1, r, t.second);	
					}				
				}
			} else {
				for (ii t : factors[p]) {
					if (l <= r) {
						update(a[id[t.first]], l, r, - t.second);	
					} else {
						update(a[id[t.first]], l, n, - t.second);	
						update(a[id[t.first]], 1, r, - t.second);	
					}					
				}
			}
			// show();
		}
	}
} 