#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;
const int md = 998244353;
int n, a[N], s[N], c[N], f[N];
int sumC, sumF, sumP;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];

	FOR(i, 1, n) s[i] = (s[i-1] + a[i]) % md;

	/*c[0] = 1;
	int sumC = 1;
	FOR(i, 1, n) {
		c[i] = sumC;
		sumC = (sumC + c[i]) % md;
	}	*/

	sumP = 1;
	f[1] = s[1];

	f[2] = (f[1] + s[1] + s[2]) % md;

	sumP = s[1];
	sumF = (f[1] + f[2]) % md;

	FOR(i, 3, n) {
		sumP = (2 * sumP % md + s[i-1]) % md;
		f[i] = ((sumF + sumP) % md + s[i]) % md;
		sumF = (sumF + f[i]) % md;
		//cerr << f[i] << " " << sumF << " " << sumP << "\n";
	}
	cout << f[n];
}
