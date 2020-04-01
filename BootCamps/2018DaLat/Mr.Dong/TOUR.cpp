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

const int N = 1000 + 5;
const int K = 15;
const ll oo = 1e17 + 7;

int n, m, k;
ll dist[N][N];
vector<ii> adj[N];
ll dp[(1<<K) + 5][K+2][K+2];
int s[N];

void dj(int s, ll dist[]) {
    //FOR(i, 1, n) dist[i] = oo;
    dist[s] = 0;

    priority_queue<li, vector<li>, greater<li> > pq;
    pq.push(mp(0, s));

    while (!pq.empty()) {
        ll d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (d > dist[u]) continue;

        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist[v.fi] > d + v.se) {
                dist[v.fi] = d + v.se;
                pq.push(mp(dist[v.fi], v.fi));
            }
        }
    }
}
int main() {
    freopen("TOUR.inp", "r", stdin);
    //freopen("TOUR.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 0, k-1) scanf("%d", &s[i]);
    int u, v, c;
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(mp(v, c));
    }

    FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = oo;
    FOR(i, 0, k-1) dj(s[i], dist[s[i]]);
    dj(1, dist[1]);

    /*FOR(i, 1, n) cerr << dist[1][i] << " "; cout << endl;
    REP(i, k) {
        FOR(j, 1, n) cerr << dist[s[i]][j] << " "; cout << endl;
    }*/

    REP(mask, 1<<k)
    REP(i, k) REP(j, k) dp[mask][i][j] = oo;

    FOR(mask, 1, (1<<k) - 1)
    REP(i, k) if ((mask & (1 << i)) > 0)
        if (__builtin_popcount(mask) == 1) dp[mask][i] = 0;
        else {
            REP(l, k) if ((mask & (1 << l)) > 0 && l != j && dist[s[l]][s[j]] != oo)
            dp[mask][i][j] = min(dp[mask][i][j], dp[mask^(1<<j)][i][l] + dist[s[l]][s[j]]);
            //printf("dp[%d][%d][%d] = %lld\n", mask, i, j, dp[mask][i][j]);
        }

    ll res = oo;
    REP(j, k) if (1 != j) {
        res = min(res, dp[(1<<k) - 1][1][j] + dist[s[j]][1]);
        //printf("%d %d %lld %lld\n", i, j, dist[1][s[i]], dist[s[j]][1]);
    }
    if (res == oo) printf("-1\n");
    else printf("%lld\n", res);

    return 0;
}
/** Happy Coding ^^ */

