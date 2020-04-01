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
#define task "E"
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, idx;
int a[N], b[N], pos[N];
vi adj[N];

void dfs(int u, int par) {
	b[++idx] = u;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	while (tc --) {
		cin >> n;
		REP(i, n - 1) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		FOR(i, 1, n) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		FOR(i, 1, n) sort(all(adj[i]), [](int u, int v) {
			return pos[u] < pos[v];
		});
		idx = 0;
		dfs(a[1], -1);
		bool flag = 1;
		FOR(i, 1, n) {
			if (b[i] != a[i]) {
				flag = 0;
				break;
			} 
		} 
		cout << (flag ? "YES\n" : "NO\n");
		FOR(i, 1, n) adj[i].clear();
	}
}
