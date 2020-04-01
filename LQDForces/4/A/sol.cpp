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

int tc, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> tc;
	while (tc --) {
		cin >> n;
		int tmp = 1, cnt = 1, res = 0;
		while (tmp <= n) {
			if (tmp * 10 <= n) {
				res += 9 * tmp * cnt;
			} else res += (n - tmp + 1) * cnt;
			cnt ++;
			tmp *= 10;
		}
		cout << res << '\n';
	}	
}
