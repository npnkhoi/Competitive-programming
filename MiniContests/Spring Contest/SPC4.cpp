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

#define task "SPC4"

typedef long long ll; 
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 30;

int tc, r, c;
char a[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> tc;
	REP(NhiThunDangIu, tc) {
		cin >> r >> c;
		int lastRow = -1;
		FOR(i, 1, r) {
			int last = -1;
			FOR(j, 1, c) {
				cin >> a[i][j];
				if (a[i][j] == '?') {
					if (last != -1) a[i][j] = a[i][last];
				} else {
					if (last == -1) {
						FOR(k, 1, j - 1) a[i][k] = a[i][j];
					}
					last = j;
				}
			}
			if (last == -1) {
				if (lastRow != -1) {
					FOR(j, 1, c) a[i][j] = a[lastRow][j];
				}
			} else {
				if (lastRow == -1) {
					FOR(k, 1, i - 1) {
						FOR(j, 1, c) a[k][j] = a[i][j];
					}
				}
				lastRow = i;
			}
		}
		FOR(i, 1, r) {
			FOR(j, 1, c) cout << a[i][j];
			cout << '\n';
		}
	}
}
