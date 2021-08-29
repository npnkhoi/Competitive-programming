#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "SPC6"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 55;

int tc, n, a[N];
ll m;

bool getBit(ll x, int i) {
	return (x >> i) & 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> tc;
	REP(NhiThunXinhDep, tc) {
		cin >> n >> m;

		if (n == 1) {
			if (m == 1) {
				cout << "POSSIBLE\n0\n";
			} else cout << "IMPOSSIBLE\n";
			continue;
		}

		if (m > (1LL << n - 2)) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		cout << "POSSIBLE\n";
		m --;
		a[n] = 1;
		FOR(i, 0, n - 3) a[n-1-i] = (getBit(m, i));
		FOR(j, 1, n) cout << a[j]; cout << '\n';
		FOR(i, 2, n) {
			FOR(j, 1, n) cout << (i < j);
			cout << '\n';
		}
	}	
}
