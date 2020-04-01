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
int n, a[N][N], ft[N][N];
string request;
string toString(int n) {
	if (n < 10) {
		string res = "";
		res += (char) (n + 48);
		return res;
	}
	else return toString(n/10) + (char) (n % 10 + '0');
}
void test(int idx) {
	ofstream inp(c_str(toString(idx) + ".inp"));
	int n = Rand(1, 1024);
	inp << n << '\n';
	int q = Rand(1, 1e5);
	REP(foo, q) {
		int type = Rand(0, 1);
		if (type) {
			inp << "SET " << Rand(0, n-1) << " " << Rand(0, n-1) << " " << Rand(1000) << "\n";
		} else {
			int x = Rand(0, n-1), y = Rand(0, n-1);
			inp << "SUM " << x << " " << y << "  " << Rand(x, n-1) << " " << Rand(y, n-1) << "\n";
		}
	}
	inp << "END\n";
	inp.close();
}
void update(int x, int y, int val) {
	for (int i = x; i <= n; i += i&-i) 
	for (int j = y; j <= n; j += j&-j) 
		ft[i][j] += val;
}
int get(int x, int y) {
	int res = 0;
	for (int i = x; i; i -= i&-i)
		for (int j = y; j; j -= j&-j) {
			res += ft[i][j];
		}
	return res;
}
int get(int x, int y, int u, int v) {
	ll res = get(u, v);
	if (x > 0) res -= get(x-1, v);
	if (y > 0) res -= get(u, y-1);
	if (x > 0 && y > 0) res += get(x-1, y-1);
	return (int) res;
}
int myMain(int idx) {
	freopen(c_str(toString(idx) + ".inp"), "r", stdin);
	freopen(c_str(toString(idx) + ".out"), "w", stdout);
	cin >> n;
	while (cin >> request) {
		if (request[0] == 'E') break;
		if (request[1] == 'E') {
			int x, y, val;
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
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FOR(i, 1, nTest) {
		test(i);
		myMain(i);
	}
}
