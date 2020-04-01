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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int n;
	string s;

	cin >> n;
	s = to_string(n);
	FORD(i, s.size() - 1, 0) {
		if (s[i] != '9') {
			s[i] = s[i] + 1;
			FOR(j, i + 1, s.size() - 1) s[j] = '1';
			cout << s << '\n';
			exit(0);
		}
	}
	REP(i, s.size() + 1) cout << '1';
}
