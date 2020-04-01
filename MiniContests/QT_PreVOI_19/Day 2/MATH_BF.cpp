#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "MATH"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int Q = 1e6 + 5, N = 1e6 + 5;

struct Query {
	int x, y, u, v, c;
	Query() {}
	Query(int x, int y, int u, int v, int c): x(x), y(y), u(u), v(v), c(c) {}
} query[Q];

vector<vector<lint> > pre, a;
int m, n, q, xx, yy;
lint col[N], colsLe[N], colsRi[N], row[N], rowsHi[N], rowsLo[N];

void Resize(vector<vector<lint> > &a, int m, int n) {
	a.resize(m + 5);
	REP(i, m + 5) a[i].assign(n + 5, 0);
} 

void Input() {
	cin >> m >> n;
	Resize(a, m, n);

	FOR(i, 1, m) {
		FOR(j, 1, n) {
			cin >> a[i][j];
		}
	}
	cin >> q;
	FOR(i, 1, q) {
		int x, y, u, v, c;
		cin >> x >> y >> u >> v >> c;
		query[i] = Query(x, y, u, v, c);
		FOR(i, x, u) FOR(j, y, v) a[i][j] += c;
	}
}

void Solve() {
	lint res = 1e18 + 7;
	FOR(z, 1, q) {
		lint tmp = 0;
		FOR(i, query[z].x, query[z].u) 
			FOR(j, query[z].y, query[z].v) {
				a[i][j] -= query[z].c;
		}
		FOR(i, 1, m) {
			FOR(j, 1, n) tmp = max(tmp, a[i][j]);
		}
		FOR(i, query[z].x, query[z].u) 
			FOR(j, query[z].y, query[z].v) {
				a[i][j] += query[z].c;
		}
		res = min(res, tmp);
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
	Input();
	Solve();
}
