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

int s;
vector<ii> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> s;
	FOR(x, 1, s - 1) {
		if (x + 1 < s) {
			if (s % (2 * x + 1) == 0) {
				ans.push_back(mp(x + 1, x));
			} else if (s >= x + 1 && (s - x - 1) % (2 * x + 1) == 0) {
				ans.push_back(mp(x + 1, x));
			}
		}
		if (x > 1) {
			if (s % (2 * x) == 0) {
				ans.push_back(mp(x, x));
			} else if (s >= x && (s - x) % (2 * x) == 0) {
				ans.push_back(mp(x, x));
			}
		}
	}	
	sort(all(ans));
	cout << s << ":\n";
	for (ii x : ans) cout << x.X << "," << x.Y << '\n';
}
