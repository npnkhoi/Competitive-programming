#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

int n;
vector<ll> v;

void calc(int k) {
	v.push_back((ll) n/k + (ll) k * n/k * (n/k - 1) / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	for (int i = 1; i * i <= n; ++ i) {
		if (n % i != 0) continue;
		calc(i);
		if (i * i != n) calc(n / i);
	}	
	sort(all(v));
	for (ll x : v) cout << x << ' ';
}
