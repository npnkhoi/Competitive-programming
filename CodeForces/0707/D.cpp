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
#define task ""
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 1e3 + 5, Q = 1e5 + 5;

struct Query {
	int type, x, y;
	Query() {}
} qr[Q];

int n, m, q;
int ans[Q], s[N], sum, flip[N], a[N][N];
vi adj[Q];

void dfs(int u) {
	ans[u] = sum;
	for (int v : adj[u]) {
		int i = qr[v].x, j = qr[v].y;

		if (qr[v].type == 1) {
			if (a[i][j] ^ flip[i] == 0) {
				a[i][j] ^= 1;
				++s[i];
				++sum;

				dfs(v);

				a[i][j] ^= 1;
				--s[i];
				--sum;
			} else dfs(v);
		} else if (qr[v].type == 2) {
			if (a[i][j] ^ flip[i] == 1) {
				a[i][j] ^= 1;
				--s[i];
				--sum;
				
				dfs(v);
				
				a[i][j] ^= 1;
				++s[i];
				++sum;
			} else dfs(v);
		} else if (qr[v].type == 3) {
			flip[i] ^= 1;
			sum += m - 2 * s[i];
			s[i] = m - s[i];
			
			dfs(v);
			
			flip[i] ^= 1;
			sum += m - 2 * s[i];
			s[i] = m - s[i];
		} else dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m >> q;
	FOR(i, 1, q) {
		cin >> qr[i].type;
		if (qr[i].type <= 2) {
			cin >> qr[i].x >> qr[i].y;
		} else cin >> qr[i].x;

		if (qr[i].type != 4) {
			adj[i - 1].push_back(i);
		} else {
			adj[qr[i].x].push_back(i);
		}
	}
	dfs(0);
	FOR(i, 1, q) cout << ans[i] << '\n';
}
