using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)

const int N = 2500 + 5;
const int oo = 1e9 + 7;

int n, m;
int dist[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<ii> adj[N];
ll a[N], cost[N];
bool fix[N];

void dj(int s) {
    FOR(i, 1, n) dist[i] = oo;
    dist[s] = 0;
    pq.push(mp(0, s));

    while (!pq.empty()) {
        int d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (d > dist[u]) continue;

        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist[v.fi] > dist[u] + v.se) {
                dist[v.fi] = dist[u] + v.se;
                pq.push(mp(dist[v.fi], v.fi));
            }
        }
    }
}
int main() {
    freopen("ROAD.inp", "r", stdin);
    freopen("ROAD.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%lld", &a[i]);
    REP(i, m) {
        int u, v;
        ll d;
        scanf("%d%d%d", &u, &v, &d);
        adj[u].push_back(mp(v, d));
        adj[v].push_back(mp(u, d));
    }

    cost[1] = 0;
    FOR(i, 2, n) cost[i] = 1LL*oo*oo;

    FOR(z, 2, n) {
        int s;
        ll val = 1LL * oo * oo;
        FOR(i, 1, n) if (fix[i] == 0 && cost[i] < val) {
            val = cost[i];
            s = i;
        }
        fix[s] = 1;
        //cout << s << endl;

        if (s == n) break; /// PRUNE 1
        dj(s);
        /// PRUNE 2
        bool ok = 1;
        FOR(i, 1, n) if (fix[i] == 0 && a[i] < a[s]) {
            ok = 0;
            break;
        }
        if (ok) {
            cost[n] = cost[s] + dist[n] * a[s];
            break;
        }

        FOR(i, 1, n) if (fix[i] == 0) {
            ll tmp = cost[s] + a[s] * dist[i];
            if (tmp < cost[i]) {
                cost[i] = tmp;
                //heap.push(mp(cost[i], i));
            }
        }
    }
    printf("%lld", cost[n]);
    return 0;
}
/** Happy Coding ^^ */

