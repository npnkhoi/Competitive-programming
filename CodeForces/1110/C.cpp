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
#define task ""
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

int q, a;
int f[] = {1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	// FOR(a, 2, 10000) {
	// 	int mx = -1, save = -1;
	// 	FOR(b, 1, a - 1) {
	// 		if (__gcd(a ^ b, a & b) > mx) {
	// 			mx = __gcd(a ^ b, a & b);
	// 			save = b;
	// 		}
	// 	}
	// 	cerr << a << ' ' << save << ' ' << mx << '\n';
	// }

	// FOR(i, 2, 25) {
	// 	a = (1 << i) - 1;
	// 	int res = -1;
	// 	FOR(b, 1, a - 1) res = max(res, (__gcd(a ^ b, a & b)));
	// 	f[a] = res;
	// 	cerr << res << '\n';
	// }

	cin >> q;
	while (q --) {
		cin >> a;
		if (__builtin_popcount(a + 1) != 1) {
			REP(i, 25) if ((1 << i) <= a) a |= (1 << i);
			cout << a << '\n';
		} else {
			int x = log2(a + 1);
			cout << f[x - 2] << '\n';
		}
	}
}
