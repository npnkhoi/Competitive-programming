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

const int N = 5e3 + 5;
const ll oo = 1e18 + 8;
int n, a[N];
ll f[N][N/2][2];

int cost(int x, int y) {
	return max(0, x-y+1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	int m = (n+1) / 2;
	FOR(i, 1, n) cin >> a[i];
	f[0][0][1] = oo;
	FOR(j, 1, m) f[0][j][0] = f[0][j][1] = oo;
	FOR(i, 1, n) {
		f[i][0][1] = oo; 
		FOR(j, 1, m) if (j > (i+1)/2) f[i][j][0] = f[i][j][1] = oo;
		else {
			f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1]);
			f[i][j][1] = cost(a[i+1], a[i]);
			if (i >= 2) {
				f[i][j][1] += min(
					f[i-2][j-1][0] + cost(a[i-1], a[i]), 
					f[i-2][j-1][1] + max(0, cost(a[i-1], a[i]) - cost(a[i-1], a[i-2]))
				);
				//cerr << f[i-2][j-1][0] + cost(a[i-1], a[i]) << " " << f[i-2][j-1][1] + max(0, cost(a[i-1], a[i]) - cost(a[i-1], a[i-2])) << "\n";
			}
			//cerr << i << " " << j << " " << f[i][j][0] << " " << f[i][j][1] << "\n";

		}
	}
	FOR(j, 1, m) cout << min(f[n][j][0], f[n][j][1]) << " ";
}
