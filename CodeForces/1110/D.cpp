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
int cnt[N], f[2][7][7];

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

	REP(x, 7) REP(y, 7) f[0][x][y] = oo;

	FOR(x, 0, min(6, cnt[1])) 
		FOR(y, 0, min(6, cnt[2])) 
			f[0][x][y] = (cnt[1] - x) % 3 + (cnt[2] - y) % 3;

	int cur = 0;

	FOR(i, 3, m) {
		cur ^= 1;
		FOR(x, 0, 6) FOR(y, 0, 6) f[cur][x][y] = oo;

		FOR(y, 0, min(6, cnt[i - 1])) {
			FOR(z, 0, min(6, cnt[i])) {
				int t = min(min(2, cnt[i - 2]), min(cnt[i - 1] - y, cnt[i] - z));
				FOR(x, 0, t) {
					f[cur][y][z] = min(f[cur][y][z], f[cur ^ 1][x][y + x] + (cnt[i] - z - x) % 3);
				}
				// cerr << i << ' ' << y << ' ' << z << ' ' << f[cur][y][z] << '\n'; 
				// debug(t);
 			}
		}
	}
	
	cout << (n - f[cur][0][0]) / 3;
}
