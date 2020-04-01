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
typedef pair<ll, int> li;
const int MAX_SUM = 135;
ll f[17][140];
string str;
ll cnt(ll num, int s) {/// amount of number k that smaller than n and S(k) == s
	str.clear();
	while (num > 0) str = (char) (num % 10 + '0') + str, num /= 10;
	int n = (int) str.size();

	memset(f, 0, sizeof f);
	int curS = 0;
	FOR(i, 1, n) {
		REP(d, str[i-1] - '0') f[i][curS + d] ++;
		curS += str[i-1] - '0';

		FOR(j, 0, s) {
			FOR(d, 0, min(9, j)) f[i][j] += f[i-1][j - d];
			//cerr << "f " << i << " " << j << " " << f[i][j] << "\n";
		}
	}
	//cerr << str << " " << s << "->" << f[n][s] << "\n";
	return f[n][s];
}
ll nextNum(ll n, int s) { 
	//cerr << "nxt " << n << " " << s << "\n";
	ll l = n+1, r = 1e15 + 1, res = -1;
	ll cntN = cnt(n + 1, s);
	while (l <= r) {
		//cerr << l << " " << r << "\n";
		ll mid = (l + r) / 2;
		if (cnt(mid+1, s) > cntN) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	if (cnt(res+1, s) > cntN) return res;
	else return -1;
}
ll nextNum(ll num) {
	//cerr << "nxt " << num << "\n";
	li res = mp(-1, -1);
	FOR(i, 1, MAX_SUM) {
		ll tmp = nextNum(num, i);
		//cerr << tmp << "\n";
		if (tmp == -1) continue;
		if (res.fi == -1 || tmp * res.se < res.fi * i || (tmp * res.se == res.fi * i && tmp < res.fi)) {
			res = mp(tmp, i); 
			//cerr << res.fi << "ahihi\n";
		}
	}
	return res.fi;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int k;
	cin >> k;
	cerr << k;
	long long res = 1;
	REP(khue, k) {
		cout << res << '\n';
		res = nextNum(res);
	}
	//cerr << nextNum(1);
}
