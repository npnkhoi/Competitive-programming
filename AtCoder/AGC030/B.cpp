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

const int N = 2e5 + 5;

int l, n, a[N];

int dist(int u, int v, int dir) {
	if ((dir == 0) ^ (u > v)) return a[v] - a[u];
	else return a[u] + l - a[v];
}

ll calc(int pos, int l, int r, int dir) {
	if (l > r) return 0;
	if (dir == 0) return calc(l, l + 1, r, 1) + dist(pos, l, 0);
	else return calc(r, l, r - 1, 0) + dist(pos, r, 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> l >> n;
	FOR(i, 1, n) cin >> a[i];
	cout << max(calc(0, 1, n, 0), calc(0, 1, n, 1));
}
