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
#define task "CSMARKET"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 200 + 5;
const int M = 2e4 + 5;
const int oo = 1e9 + 7;
const double EPS = 1e-4;
struct Edge{
	int u, v, c;
	Edge(): u(0), v(0), c(0) {}
	Edge(int _u, int _v, int _c): u(_u), v(_v), c(_c) {}
} e[M];
int n, m, d[N][N], maxDist[N];
double calc(int u, int v, int c, double mid) {
	double res = 0;
	FOR(i, 1, n) {
		res = max(res, min(d[i][u] + mid, d[i][v] + c - mid));
	}
	return res;
} 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, n) if (i != j) d[i][j] = oo; 
	REP(i, m) {
		int u, v, c;
		cin >> u >> v >> c;
		e[i] = Edge(u, v, c);
		d[u][v] = d[v][u] = min(d[u][v], c);
	}			
	//cerr << "ok\n";
	FOR(k, 1, n) 
		FOR(i, 1, n) 
			FOR(j, 1, n) 
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	//cerr << "ok\n";
	FOR(i, 1, n) {
		FOR(j, 1, n) maxDist[i] = max(maxDist[i], d[i][j]);
	}
	//cerr << "ok\n";
	double res = oo;
	FOR(i, 1, n) res = min(res, (double) maxDist[i]);
	REP(i, m) {
		int u = e[i].u, v = e[i].v, c = e[i].c;
		double l = EPS, r = c, bs = l;
		while (r - l >= EPS) {
			double mid = (l+r) / 2;
			if (calc(u, v, c, mid - EPS) >= calc(u, v, c, mid)) {
				bs = mid;
				l = mid + EPS;
			} else r = mid - EPS;
		}
		res = min(res, calc(u, v, c, bs));
	}
	cout << fixed;
	cout << setprecision(2) << res;
}
