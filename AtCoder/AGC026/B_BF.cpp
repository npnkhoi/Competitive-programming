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
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

string calc(int a, int b, int c, int d) {
	int x = a;
	FOR(i, 1, 10000) {
		if (x > c) x = c + (x - c) % b;
		if (x < b) return "FALSE";
		else {
			x -= b;
			if (x <= c) x += d;
		}
	}
	return "TRUE";
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	FOR(c, 1, 10)
	FOR(b, c + 1, 10)
	FOR(d, b + 1, 10)
	FOR(a, b, 10)
		cout << c << " " << b  << " " << d << "  " << a << " " << calc(a, b, c, d) << "\n";
}
