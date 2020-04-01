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

const int N = 1e3 + 5;

int far, l, n, m;
int mark[N], d1[N], d2[N];
vi adj[N], vtx;
vector<ii> v;

void dfs(int u, int par, int id, int d, int dist[]) {
    if (id == 1) vtx.push_back(u);
    dist[u] = d;
    if (d > l) {
        l = d;
        far = u;
    }
    mark[u] = id;
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (mark[v] != id) {
            dfs(v, u, id, d + 1, dist);
        }
    }
}

void process(int s) {
    vtx.clear();
    far = s, l = 0;
    dfs(s, -1, 1, 0, d1);
    dfs(far, -1, 2, 0, d2);
    REP(i, vtx.size()) {
        int u = vtx[i];
        if (d1[u] == l / 2 && d2[u] == (l + 1) / 2) {
            v.push_back(mp(l, u));
            break;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n) {
        if (!mark[i]) process(i);
    }
    sort(all(v), greater<ii>());
    if (v.size() == 1) cout << v[0].fi;
    else if (v.size() == 2) {
        cout << (v[0].fi + 1) / 2 + 1 + (v[1].fi + 1) / 2 << '\n';
        cout << v[0].se << ' ' << v[1].se << '\n';
    } else {
        int res, x, y;
        res = (v[1].fi + 1) / 2 + 2 + (v[2].fi + 1) / 2;
        x = v[1].se; y = v[2].se;
        if ((v[0].fi + 1) / 2 + 1 + (v[1].fi + 1) / 2 < res) {
            res = (v[0].fi + 1) / 2 + 1 + (v[1].fi + 1) / 2;
            x = v[0].se, y = v[1].se;
        }
        if ((v[0].fi + 1) / 2 + 1 + (v[2].fi + 1) / 2 < res) {
            res = (v[0].fi + 1) / 2 + 1 + (v[2].fi + 1) / 2;
            x = v[0].se, y = v[2].se;
        }
        cout << res << '\n' << x << ' ' << y;
    }
}
