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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;1
const ll md = 998244353;

int n;
ll fac[N], rev[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	fac[0] = 1; rev[0] = 1;
	FOR(i, 1, n) {
		fac[i] = fac[i - 1] * i % md;
		rev[i] = rev[i - 1] * (n - i + 1) % md;
		//cerr << fac[i] << ' ' << rev[i] << '\n';
	}
	ll res = fac[n];
	FOR(k, 1, n - 1) {
		res = (res + fac[n] - rev[k]) % md;
	}
	if (res < 0) res += md;
	cout << res;
}
