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

ll n, m, coef1, coef2, x, d, res;
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m;
	coef1 = n * (n - 1) / 2;
	coef2 = (n/2) * (n/2 + 1) / 2 + ((n-1)/2) * ((n-1)/2 + 1) / 2;
	FOR(i, 1, m) {
		cin >> x >> d;
		if (d > 0) res += x * n + d * coef1;
		else res += x * n + d * coef2;
	}	
	cout << fixed << setprecision(10);
	cout << (double) res / n;
}
