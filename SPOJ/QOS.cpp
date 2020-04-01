using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e3 + 5;
const int D = 1e5 + 5;
const int oo = 1e9 + 7;
int n, m, t;
vector<ii> adj[N], adj2[N];
int dist[N];
int L;
ll k, memo[N][D];
vector<int> ans;
void Dijsktra(int s) {
    for (int i = 1; i <= n; i++) dist[i] = oo;
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    heap.push(mp(0, s));
    while (!heap.empty()) {
        int u = heap.top().se, d = heap.top().fi;
        heap.pop();
        if (d > dist[u]) continue;
        REP(j, adj2[u].size()) {
            ii t = adj2[u][j];
            if (dist[t.fi] > d + t.se) {
                dist[t.fi] = d + t.se;
                heap.push(mp(dist[t.fi], t.fi));
            }
        }
    }
}
ll dp(int u, int d) {
    //printf("dp %d %d\n", u, d);
    if (d + dist[u] > L) return 0;
    if (memo[u][d] != -1) return memo[u][d];
    if (u == t) return memo[u][d] = (d <= L);
    ll s = 0;
    REP(j, adj[u].size()) {
        ii v = adj[u][j];
        s += dp(v.fi, d + v.se);
    }
    return memo[u][d] = s;
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d %d %lld", &n, &m, &t, &k);
    int u, v, c;
    L = oo;
    REP(i, m) {
        scanf("%d %d %d", &u, &v, &c);
        adj[u].pb(mp(v, c));
        adj2[v].pb(mp(u, c));
        L = min(L, c);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    Dijsktra(t);
    if (dist[1] == oo) { printf("-1"); return 0;}
    L += dist[1];
    memset(memo, -1, sizeof memo);
    if (k > dp(1, 0)) { printf("-1"); return 0;}
    int d = 0; u = 1;
    ans.pb(1);
    while (u != t || k > 1) {
        ll s = 0;
        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (s + dp(v.fi, d + v.se) >= k) {
                k -= s;
                u = v.fi;
                d += v.se;
                ans.pb(v.fi);
                break;
            }
            else s += dp(v.fi, d + v.se);
        }
    }
    printf("%d\n", ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);
    return 0;
}
/** Happy Coding ^^ */

