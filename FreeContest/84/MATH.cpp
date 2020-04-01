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
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

char s[10];
char sign;
vi ans;
bool ok(int a, int b, int c) {
	if (a / 10 != s[0] - '0' && s[0] != '?') return false;
	if (a % 10 != s[1] - '0' && s[1] != '?') return false;
	if (b / 10 != s[3] - '0' && s[3] != '?') return false;
	if (b % 10 != s[4] - '0' && s[4] != '?') return false;
	if (c / 10 != s[6] - '0' && s[6] != '?') return false;
	if (c % 10 != s[7] - '0' && s[7] != '?') return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	REP(khue, tc) {
		REP(i, 8) cin >> s[i];
		//REP(i, 8) cerr << s[i] << "\n";
		//flag = 1;
		FOR(a, 10, 99) FOR(b, 10, 99 - a) {
			if (ok(a, b, a+b) && s[2] != '-') {
				ans = {a, b, a+b};
				sign = '+';
			}
			if (ok(a+b, a, b) && s[2] != '+') {
				ans = {a+b, a, b};
				sign = '-';
			}
		}		
		cout << ans[0] << " " << sign << " " << ans[1] << " = " << ans[2] << "\n"; 
	}
}
