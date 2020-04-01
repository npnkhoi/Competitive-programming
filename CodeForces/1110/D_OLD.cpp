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

const int N = 1e6 + 5, oo = 1e9 + 7;

int n, m, x;
int cnt[N], f[N][3][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> x;
		cnt[x] ++;
	}
	FOR(i, 2, m) REP(x, 3) REP(y, 3) f[i][x][y] = oo;
	REP(x, min(3, cnt[1] + 1)) REP(y, min(3, cnt[2] + 1)) f[2][x][y] = x + y;
	
	FOR(i, 3, m) {
		REP(x, min(3, cnt[i - 1] + 1)) {
			REP(y, min(3, cnt[i] + 1)) {
				int a = cnt[i - 2] % 3, b = x, c = y;

				REP(NhiThun, 3) {
					if (c <= cnt[i]) 
						f[i][x][y] = min(f[i][x][y], f[i - 1][a][b] + c);
					a = (a + 2) % 3;
					b = (b + 2) % 3;
					c = (c + 2) % 3;
				}
				// cerr << i << ' ' << x << ' ' << y << ' ' << f[i][x][y] << '\n';
			} 
		}
	}
	// cerr << f[m][cnt[m - 1] % 3][cnt[m] % 3] << '\n';
	cout << (n - f[m][cnt[m - 1] % 3][cnt[m] % 3]) / 3;
}
