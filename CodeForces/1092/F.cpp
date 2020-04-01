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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;

int n, a[N];
ll s[N], up[N], down[N];
vi adj[N];

void dfs1(int u, int par) {
    s[u] = a[u];
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == par) continue;
        dfs1(v, u);
        s[u] += s[v];
        down[u] += down[v] + s[v];
    }
}

void dfs2(int u, int par) {
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == par) continue;
        up[v] = up[u] + s[1] - s[u]
            + down[u] - (down[v] + s[v]) + s[u] - s[v];
        dfs2(v, u);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    //cerr << '\n';
    //FOR(i, 1, n) cerr << up[i] << ' ' << down[i] << '\n';
    ll res = 0;
    FOR(i, 1, n) res = max(res, up[i] + down[i]);
    cout << res;
}

