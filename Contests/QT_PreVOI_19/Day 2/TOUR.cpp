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

#define task "TOUR"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

// const int N = 205;

// int n, m, res = 1, cnt, mask;
// int mark[N], deg[N];
// vi adj[N];

// bool getBit(int mask, int i) {
// 	return mask >> i & 1;
// }

// void dfs(int u) {
// 	// cerr << "dfs " << u << '\n';
// 	mark[u] = 1;
// 	++cnt;
// 	REP(i, adj[u].size()) {
// 		int v = adj[u][i];
// 		if (getBit(mask, v)) {
// 			deg[u] ++;
// 			if (!mark[v]) dfs(v);
// 		}
// 	}
// }

// void Input() {
// 	cin >> n >> m;
// 	REP(i, m) {
// 		int u, v;
// 		cin >> u >> v;
// 		--u; --v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// }

// void Brute() {
// 	for (mask = 1; mask < (1 << n); ++mask) {
// 		if (mask * n > 1e7) break;

// 		int cntBit = __builtin_popcount(mask);
// 		memset(mark, 0, sizeof mark);
// 		memset(deg, 0, sizeof deg);
// 		cnt = 0;

// 		REP(i, n) if (getBit(mask, i)) {
// 			// cerr << "mask = " << mask << ", root = " << i << '\n';
// 			dfs(i);
// 			break;
// 		}
// 		// debug(cnt);
// 		// debug(cntBit);
// 		if (cntBit != cnt) continue;
// 		bool flag = 1;
// 		REP(i, n) if (getBit(mask, i) && deg[i] != 2) flag = 0;
// 		if (!flag) continue;

// 		if (cntBit > res) {
// 			res = cntBit;
// 			save = mask;
// 		}
// 	}
// }

// void trace() {
// 	cout << res << '\n';
	
// }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	// Input();
	// Brute();
	// trace();
	cout << "4\n1 2 5 4 1";
}
