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

const int N = 35;

int m, n, lo[N], hi[N];
char a[N][N];
lint f[N][N], s[N];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> m >> n;

	FOR(i, 1, m) {
		int posB = 0, posR = n + 1;
		FOR(j, 1, n) {
			cin >> a[i][j];
			if (a[i][j] == 'R' && posR == n + 1) posR = j;
			if (a[i][j] == 'B') posB = j; 
		}
		if (posB > posR) {
			cout << "0\n";
			exit(0);
		}
		lo[i] = posB;
		hi[i] = posR - 1;
		// cerr << lo[i] << ' ' << hi[i] << '\n';
	}
	FOR(j, 0, n) s[j] = 1;
	FOR(i, 1, m) {
		FOR(j, lo[i], hi[i]) f[i][j] = s[j];
		FORD(j, n, 0) s[j] = f[i][j] + s[j + 1];
	}
	cout << s[0];
}
