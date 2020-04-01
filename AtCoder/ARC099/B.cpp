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

ll EXP[20];
int sumDigit(ll x) {
	if (x == 0) return 0;
	else return x % 10 + sumDigit(x / 10);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	EXP[0] = 1;
	FOR(i, 1, 18) EXP[i] = EXP[i-1] * 10;

	int k;
	cin >> k;
	long long x = 1;

	REP(khue, k) {
		cout << x << '\n';
		
		x ++;
		int s = sumDigit(x);
		li res = mp(x, s);
		for (int i = 0; EXP[i] <= x; i++) {
			int tmp = x % EXP[i+1] / EXP[i];
			x += (9 - tmp) * EXP[i];
			s += (9 - tmp);
			if (x * res.se < res.fi * s) res = mp(x, s);
		}
		x = res.fi;
	}
	//cerr << nextNum(1);
}
