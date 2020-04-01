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
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105;
int a, b, f[N][N];
bool ok(int i, int j) {
	if (i > 1 && f[i-1][j] != f[i][j]) return false;
	if (i < 100 && f[i+1][j] != f[i][j]) return false;
	if (j > 1 && f[i][j-1] != f[i][j]) return false;
	if (j < 100 && f[i][j+1] != f[i][j])  return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> a >> b;
	a --; b--;
	FOR(i, 1, 50) FOR(j, 1, 100) f[i][j] = 1;
	for (int i = 1; i <= 50 && a > 0; i += 2) {
		for (int j = 1; j <= 100 && a > 0; j += 2) {
			f[i][j] = 0;
			a--;
		}
	}
	for (int i = 52; i <= 100 && b > 0; i += 2) {
		for (int j = 1; j <= 100 && b > 0; j += 2) {
			f[i][j] = 1;
			b--;
		}
	}
	cout << "100 100\n";
	FOR(i, 1, 100) {
		FOR(j, 1, 100) cout << (f[i][j] ? '#' : '.');
		cout << "\n";
	}
}
