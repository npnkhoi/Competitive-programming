using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 5000 + 5;
const ll oo = 1e16;
vector<int> adj[N];
pair<ii, int> inf[N];
int n, m, w, d[N];
ll cost(int k, int dist) {
    ll res = 0;
    for (int i = 0; i < w && k > 0; i++) {
        int u = inf[i].se;
        int x = inf[i].fi.fi;
        int y = inf[i].fi.se;
        if (d[u] <= dist && d[u] != -1)
        if (y <= k) {
            k -= y;
            res += 1LL * y * x;
        }
        else {
            res += 1LL * k * x;
            k = 0;
        }
    }
    if (k == 0) return res;
    else return oo;
}
void dfs(int u, int dist) {
    d[u] = dist;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (d[v] == -1) dfs(v, dist + 1);
    }
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &m);
    int u, v;
    REP(z, m) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q, c, k, p;
    scanf("%d", &w);
    REP(z, w) {
        scanf("%d %d %d", &c, &k, &p);
        inf[z] = mp(mp(p, k), c);
    }
    sort(inf, inf + w);
    scanf("%d", &q);
    while (q--) {
        //cout << "----------------------------\n";
        scanf("%d %d %d", &c, &k, &p);
        queue<int> q; q.push(c);
        memset(d, -1, sizeof d); d[c] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        //for (int i = 1; i <= n; i++) printf("%d ", d[i]); cout << "\n";

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (cost(k, mid) <= 1LL * p) r = mid;
            else l = mid + 1;
        }
        if (cost(k, l) > 1LL * p) printf("-1\n");
        else printf("%d\n", l);
    }
    return 0;
}
/** Happy Coding ^^ */
