#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()
#define task "SUM"
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 5005, A = 1e6 + 5;

int n, m;
int a[N], b[N], sie[A], f[A];
map<int, int> cnt;
vector<int> v, primes;

lint calc(int x) {
	// cerr << x << '\n';
	if (x <= 1e6) return f[x];
	int res = 0;
	for (int t : primes) {
		if ((lint) t * t > x) break;
		while (x % t == 0) {
			res += t;
			x /= t;
		}
	}
	if (x > 1) res += x;
	return res;
}

void sub1() {
	// init sums
	// FOR(i, 1, n) FOR(j, 1, m) {
	// 	cnt[abs(a[i] - b[j])] ++;
	// 	// if (a[i] + b[j] > 1e6) v.push_back(a[i] + b[j]);
	// }
	// sort(all(v));
	// v.resize(unique(v.begin(), v.end()) - v.begin());
	// sie2.assign(v.size(), 0);

	// sieve and DP
	FOR(i, 2, 1e6) {
		if (sie[i] == 0) { // i is prime
			primes.push_back(i);
			sie[i] = i;
			f[i] = i;
			for (lint j = (lint) i * i; j <= 1e6; j += i) {
				if (sie[j] == 0) {
					sie[j] = i;
					// f[j] = i + (f[j / i] == 0 ? j / i : f[j / i]);
				}
			}
		}
		// cerr << i << ' ' << f[i] << '\n';
	}
	FOR(i, 2, 1e6) {
		if (sie[i] < i) f[i] = sie[i] + f[i / sie[i]];
	}
	// cerr << f[10000] << '\n';
	// calc ans
	lint res = 0;
	// for (auto it = cnt.begin(); it != cnt.end(); ++ it) {
	// 	res += calc(it -> first) * (it -> second);
	// }
	FOR(i, 1, n) FOR(j, 1, m) {
		res += calc(abs(a[i] - b[j]));
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, m) cin >> b[i];
	sub1();
	// if (m <= 5000 && n <= 5000) sub1();
	// else sub2();
}
