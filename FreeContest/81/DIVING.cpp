#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "diving"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e4 + 5;
const int L = 10;
const int id0 = 9;
const int oo = 1e9 + 7;
int tc, n, m, k, l, tlimit, res, tmp;
vector<ii> adj[N];
vi data;
int dist[L][N], p[L], cnt[N], dp[(1 << 8) + 5][L];
priority_queue<ii, vector<ii>, greater<ii> > heap;

void dijsktra(int s, int id) {
    REP(u, n) dist[id][u] = oo; dist[id][s] = 0;
    heap.push(mp(0, s));
    while (!heap.empty()) {
        int u = heap.top().se, d = heap.top().fi;
        heap.pop();
        if (d > dist[id][u]) continue;
        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist[id][v.fi] > d + v.se) {
                dist[id][v.fi] = d + v.se;
                heap.push(mp(v.fi, dist[id][v.fi]));
            }
        }
    }
    /*cerr << "dist " << s << " " << id << "\n";
    REP(i, n) cerr << dist[id][i] << " ";
    cerr << "\n";*/
}
int main() {
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d%d", &n, &m);
        //cerr << n << " " << m << "\n";
        REP(i, n) adj[i].clear();
        REP(z, m) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            //cerr << u << " " << v << " " << c << "\n";
            adj[u].push_back(mp(v, c));
            adj[v].push_back(mp(u, c));
        }
        scanf("%d", &k);
        data.clear();
        FOR(i, 1, k) {
            scanf("%d", &p[i]);
            //cerr << p[i] << "\n";
            cnt[p[i]] ++;
            if (cnt[p[i]] == 1 && p[i] != 0) data.pb(p[i]);
        }
        scanf("%d", &tlimit);
        //cerr << tlimit << "\n";

        l = data.size();
        //cerr << l << "\n";
        REP(i, l) dijsktra(data[i], i);
        dijsktra(0, l);
        res = 0;
        REP(mask, (1 << l)) REP(u, l) dp[mask][u] = oo;

        FOR(mask, 1 , (1 << l) - 1) REP(u, l) if ((mask & (1 << u)) > 0) {
            int mask2 = mask ^ (1 << u);
            if (mask2 == 0) dp[mask][u] = dist[l][data[u]];
            else {
                REP(v, l) if ((mask & (1 << v)) > 0 && v != u)
                dp[mask][u] = min(dp[mask][u], dp[mask2][v] + dist[v][data[u]]);
            }
            //cerr << mask << " " << u << " " << dp[mask][u] << "\n";
            if (dp[mask][u] + dist[u][0] <= tlimit) {
                int tmp = 0;
                REP(u, n) if ((mask & (1 << u)) > 0) tmp += cnt[data[u]];
                res = max(res, tmp + cnt[0]);
            }
        }
        printf("%d\n", res);
        FOR(i, 1, k) cnt[p[i]] --;
        //cerr << "-----\n";
    }
}

