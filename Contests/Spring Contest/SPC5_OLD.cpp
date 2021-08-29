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

#define task "SPC5"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1005, md = 1e9 + 7;

int tc, n, k;
int f[N][N][5];

void inc(int &x, int y) {
	x += y;
	while (x < 0) x += md;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> tc;
	REP(NhiThunCute, tc) {
		cin >> n >> k;
		f[0][0][0] = 1;
		FOR(i, 1, n) {
			FOR(j, 0, i) {
				REP(mask, 4) {
					f[i][j][mask] = 0;
					if (j > 0) {
						if (i < n) {
							inc(f[i][j][mask], f[i - 1][j - 1][2 | (mask >> 1)]);
							inc(f[i][j][mask], f[i - 1][j - 1][0 | (mask >> 1)]);
						}
						if (mask & 2) {
							inc(f[i][j][mask], f[i - 1][j - 1][2]);
							inc(f[i][j][mask], f[i - 1][j - 1][0]);
						}
					}
					if (i > 1) inc(f[i][j][mask], f[i - 1][j][2 | (mask >> 1)]);
					inc(f[i][j][mask], f[i - 1][j][0 | (mask >> 1)]);
					cerr << i << ' ' << j << ' ' << mask << ' ' << f[i][j][mask] << '\n';
				}
			}
		}
		int res = 0;
		REP(mask, 4) inc(res, f[n][k][mask] - f[n][k + 1][mask]);
		cout << res << '\n';
	} 
}
