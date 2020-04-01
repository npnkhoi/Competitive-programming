#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "COLPATHS"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 3e5 + 5, K = 7;

int n, m, k, col[N], mark[K];
ll res;
vi adj[N], v;

void input() {
	cin >> n >> m >> k;
	FOR(i, 1, n) {
		cin >> col[i];
	}
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void brute(int i) {
    int u = v.back();
    REP(j, adj[u].size()) {
        int nxt = adj[u][j];
        if (!mark[col[nxt]]) {
            res ++;
            mark[col[nxt]] = 1;
            v.push_back(nxt);
            brute(i + 1);
            mark[col[nxt]] = 0;
            v.pop_back();
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".ans", "w", stdout);
	input();
	v.resize(1);
    res = n;
	FOR(i, 1, n) {
	    mark[col[i]] = 1;
        v[0] = i;
        brute(2);
        mark[col[i]] = 0;
    }
    cout << res;
}
