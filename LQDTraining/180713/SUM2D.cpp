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
#define task "SUM2D"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1030;
int n;
ll a[N][N];
ll ft[N][N];
string request;

void update(int x, int y, int val) {
	for (int i = x; i <= n; i += i&-i) 
	for (int j = y; j <= n; j += j&-j) 
		ft[i][j] += val;
}
ll get(int x, int y) {
	ll res = 0;
	for (int i = x; i; i -= i&-i)
		for (int j = y; j; j -= j&-j) {
			res += ft[i][j];
		}
	return res;
}
ll get(int x, int y, int u, int v) {
	ll res = get(u, v);
	if (x > 0) res -= get(x-1, v);
	if (y > 0) res -= get(u, y-1);
	if (x > 0 && y > 0) res += get(x-1, y-1);
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n;
	while (cin >> request) {
		if (request[0] == 'E') break;
		if (request[1] == 'E') {
			int x, y;
			ll val;
			cin >> x >> y >> val;
			x ++; y ++;
			update(x, y, val - a[x][y]);
			a[x][y] = val;
		} else {
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			cout << get(x + 1, y + 1, u + 1, v + 1) << "\n";
		}
	}
}
