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

const int N = 305;

int tc, n, a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);	
	cin >> tc;
	while (tc --) {
		cin >> n;
		FOR(i, 1, n) cin >> a[i];

		int cnt = 0;
		FOR(i, 1, n - 2) {
			FOR(j, i + 1, n - 1) {
				FOR(k, j + 1, n) {
					if (a[i] > abs(a[j] - a[k]) && a[i] < a[j] + a[k]) {
						++ cnt;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}