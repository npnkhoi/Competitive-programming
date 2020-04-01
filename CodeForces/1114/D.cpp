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

const int N = 5005;

int n, a[N], f[N][N][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FORD(l, n, 1) {
		FOR(r, l + 1, n) {
			f[l][r][0] = 
				min(f[l + 1][r][0] + (a[l] != a[l + 1]), f[l + 1][r][1] + (a[l] != a[r]));
			f[l][r][1] = 
				min(f[l][r - 1][0] + (a[l] != a[r]), f[l][r - 1][1] + (a[r - 1] != a[r])); 
			// cout << l << ' ' << r << ' ' << f[l][r][0] << ' ' << f[l][r][1] << '\n';
		}
	}
	cout << min(f[1][n][0], f[1][n][1]);
}
