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
#define task "C"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e3 + 5;
char s[N];
int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	FOR(iTest, 1, tc) {
		cout << "Case #" << iTest << ": ";
		cin >> s + 1;
		n = strlen(s + 1);
		bool flag = 0;
		FOR(x, 1, n - 2) if (s[1] == s[x + 1]) {
			FOR(j, x+2, n) if (s[j] != s[j - x]) {
				flag = 1;
				break;
			}
			if (flag) {
				FOR(j, 1, x) cout << s[j];
				cout << s + 1 << "\n";
				break;
			}
		}
		if (!flag) cout << "Impossible\n";
	}		
}
