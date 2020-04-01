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

const int N = 405;

int n, tc;
int x[N], y[N];

int area(int i, int j, int k) {
	return abs(
		x[i] * y[j] - x[j] * y[i] +  
		x[j] * y[k] - x[k] * y[j] +
		x[k] * y[i] - x[i] * y[k]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> tc;
	while (tc --) {
		cin >> n;
		FOR(i, 1, n) cin >> x[i] >> y[i];
		int res = 0;
		FOR(i, 1, n - 2) {
			FOR(j, i + 1, n - 1) {
				FOR(k, j + 1, n) {
					res = max(res, area(i, j, k));
				}
			}
		}
		cout << res / 2 << '.' << (res & 1 ? 5 : 0) << '\n';
	}
}
