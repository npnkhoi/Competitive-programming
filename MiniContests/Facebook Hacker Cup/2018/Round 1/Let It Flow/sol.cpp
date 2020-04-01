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
#define task "test"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1000 + 5;
const int md = 1e9 + 7;
char a[3][N];
int n, f[N][3];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	FOR(iTest, 1, tc) {
		cin >> n;
		FOR(i, 0, 2) FOR(j, 1, n) cin >> a[i][j];
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		FOR(i, 1, n) {
			REP(j, 3) if (a[j][i] == '.') {
				//cerr << "calc " << i << " " << j << "\n";
				if (j > 0 && a[j-1][i] == '.') f[i][j] = (f[i][j] + f[i-1][j-1]) % md;
				if (j < 2 && a[j+1][i] == '.') f[i][j] = (f[i][j] + f[i-1][j+1]) % md;
			}
			//cerr << f[i][0] << " " << f[i][1] << " " << f[i][2] << "\n"; 
		}
		cout << "Case #" << iTest << ": " << f[n][2] << '\n';
	}	
}
