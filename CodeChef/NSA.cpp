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

const int N = 1e5 + 5;
const ll oo = 1e18 + 7;
char s[N];
int n, cnt[N][30];

int get(int l, int r, int u, int v) {
	if (l > r || u > v) return 0;
	int res = cnt[r][v];
	if (l > 0) res -= cnt[l-1][v];
	if (u > 0) res -= cnt[r][u-1];
	if (l > 0 && u > 0) res += cnt[l-1][u-1];
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	REP(khue, tc) {
		cin >> s + 1;
		n = strlen(s+1);
		memset(cnt, 0, sizeof cnt);
		ll cost = 0;
		FOR(i, 1, n) {
			FOR(j, 0, s[i] - 'a' - 1) cnt[i][j] = cnt[i-1][j];
			FOR(j, s[i] - 'a', 25) cnt[i][j] = cnt[i-1][j] + 1;
			if (s[i] > 'a') cost += cnt[i-1][s[i] - 'a' - 1];
		}
		ll res = oo;
		FOR(i, 1, n) REP(c, 26) {
			ll tmp = cost + abs(s[i] - 'a' - c);
			tmp += get(1, i-1, 0, c-1) + get(i+1, n, c+1, 25);
			tmp -= get(1, i-1, 0, s[i] - 'a' - 1) + get(i+1, n, s[i] - 'a' + 1, 25);
			res = min(res, tmp);
		}
		cout << res << '\n';
	}			
}
