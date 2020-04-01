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

const int N = 705;
int n, m, bal;
bool hasEdge[N][N];
int color[N], f[N];
vi v;

void dfs(int u) {
	//cerr << "dfs " << u << color[u] << "\n";
	bal += color[u];
	FOR(v, 1, n) if (v != u && hasEdge[u][v] == 0) {
		if (color[v] == 0) {
			color[v] = - color[u];
			dfs(v);
		} else if (color[v] == color[u]) {
			cout << "-1";
			exit(0);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m;
	REP(i, m) {
		int u, v;
		cin >> u >> v;
		hasEdge[u][v] = hasEdge[v][u] = 1;
	}	
	int s = 0;
	FOR(u, 1, n) if (color[u] == 0) {
		color[u] = -1;
		bal = 0;
		dfs(u);
		//cerr << "----------\n";
		s += abs(bal);
		v.pb(abs(bal));
	}
	f[0] = 1;
	int tmp = 0;
	REP(j, (int) v.size()) {
		FORD(i, s/2, v[j]) f[i] |= f[i - v[j]];
	}
	FOR(i, 1, s/2) if (f[i]) tmp = i;
	//FOR(i, 0, s/2) cerr << f[i] << " "; cerr << "\n";
	int dif = s - 2 * tmp;
	int x = (n - dif) / 2;
	int y = (n + dif) / 2;
	//cerr << x << " " << y << "\n";
	cout << 1LL * x * (x - 1) / 2 + 1LL * y * (y - 1) / 2;
}