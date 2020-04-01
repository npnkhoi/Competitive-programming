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

void read(lint &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

void read(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

void Input() {
	read(m); read(n);
	Resize(a, m, n);
	Resize(pre, m, n);
	FOR(i, 1, m) {
		FOR(j, 1, n) {
			read(pre[i][j]);
		}
	}
	cin >> q;
	FOR(i, 1, q) {
		int x, y, u, v, c;
		read(x);
		read(y);
		read(u);
		read(v);
		read(c);
		// cin >> x >> y >> u >> v >> c;
		// cerr << x << ' ' << y << ' ' << u << ' ' << v << ' ' << c << '\n';
		query[i] = Query(x, y, u, v, c);
		a[x][y] += c;
		a[u + 1][y] -= c;
		a[x][v + 1] -= c;
		a[u + 1][v + 1] += c;
	}
}

void Init() {
	// FOR(i, 1, m) {
	// 	FOR(j, 1, n) cerr << a[i][j] << ' ';
	// 	cerr << '\n';
	// }
	// cerr << '\n';
	FOR(i, 1, m) {
		FOR(j, 1, n) {
			a[i][j] += a[i - 1][j];
			// cerr << a[i][j] << ' ';
		}
		// cerr << '\n';
	}
	// cerr << '\n';
	FOR(i, 1, m) {
		FOR(j, 1, n) {
			a[i][j] += a[i][j - 1];
			// cerr << a[i][j] << ' ';
		}
		// cerr << '\n';
	}
	// cerr << '\n';
	xx = yy = 1;
	FOR(i, 1, m) {
		FOR(j, 1, n) {
			// a[i][j] += a[i][j - 1];
			a[i][j] += pre[i][j];
			// cerr << a[i][j] << ' ';

			row[i] = max(row[i], a[i][j]);
			col[j] = max(col[j], a[i][j]);
			if (a[i][j] > a[xx][yy]) xx = i, yy = j;
		}
		// cerr << '\n';
	}
	FOR(i, 1, m) rowsHi[i] = max(rowsHi[i - 1], row[i]);
	FORD(i, m, 1) rowsLo[i] = max(rowsLo[i + 1], row[i]);
	FOR(j, 1, n) colsLe[j] = max(colsLe[j - 1], col[j]);
	FORD(j, n, 1) colsRi[j] = max(colsRi[j + 1], col[j]);
}

void Solve() {
	lint res = a[xx][yy];
	FOR(i, 1, q) {
		if (query[i].x <= xx && xx <= query[i].u && query[i].y <= yy && yy <= query[i].v) {
			lint tmp = a[xx][yy] - query[i].c;
			tmp = max(tmp, max(rowsHi[query[i].x - 1], rowsLo[query[i].u + 1]));
			tmp = max(tmp, max(colsLe[query[i].y - 1], colsRi[query[i].v + 1]));
			res = min(res, tmp);
		}
	}
	// cout << res << '\n';
	printf("%lld", res);
}

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	Input();
	Init();
	Solve();
}
