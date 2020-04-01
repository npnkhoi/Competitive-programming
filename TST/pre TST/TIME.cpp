#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()
#define task "TIME"
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 2210;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int m, n, k, x, y, u, v;
int dist[N][N];
queue<ii> q;
string a[N];

bool inBoard(int x, int y) {
	return 0 <= x && x <= m && 0 <= y && y <= n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> m >> n >> k;
	REP(i, m) cin >> a[i];
	cin >> x >> y >> u >> v;
	x --; y --; u --; v --;

	memset(dist, -1, sizeof dist);
	q.push({x, y});
	dist[x][y] = 0;

	while (!q.empty()) {
		ii u = q.front();
		q.pop();

		REP(dir, 4) {
			ii v = u;
			REP(i, k) {
				v.X += dx[dir];
				v.Y += dy[dir];
				if (!inBoard(v.X, v.Y) || dist[v.X][v.Y] != -1 || a[v.X][v.Y] == '#') 
					break;
				dist[v.X][v.Y] = dist[u.X][u.Y] + 1;
				q.push(v);
			}
		}
	}
	cout << dist[u][v];
}
