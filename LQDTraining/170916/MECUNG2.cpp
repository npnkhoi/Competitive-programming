using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e5 + 5;
const int oo = 1e9 + 10;
int n, m;
vector<ii> adj[N];
int dist1[N], dist2[N], save[4*N];
queue<int> q, tmp;
int main() {
    //freopen("MECUNG.inp", "r", stdin);
    //freopen("MECUNG.out", "w", stdout);
    scanf("%d %d", &n, &m);
    FOR(i, 1, m) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(mp(v, c));
        adj[v].push_back(mp(u, c));
    }
    //-----------------------------
    memset(dist1, -1, sizeof dist1);
    q.push(1); dist1[1] = 0;
    while (!q.empty()) { /// bfs minpath from 1
        int u = q.front(); q.pop();
        REP(j, adj[u].size()){
            ii v = adj[u][j];
            if (dist1[v.fi] == -1) {
                dist1[v.fi] = dist1[u] + 1;
                q.push(v.fi);
            }
        }
    }
    //-----------------------------
    memset(dist2, -1, sizeof dist2);
    q.push(n); dist2[n] = 0;
    while (!q.empty()) { /// bfs minpath from N
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist2[v.fi] == -1) {
                dist2[v.fi] = dist2[u] + 1;
                q.push(v.fi);
            }
        }
    }
    //------------------------------
    int s = dist1[n];
    printf("%d\n", s);
    q.push(1);
    FOR(i, 1, s) {
        int _min = oo;
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            FOR(j, 0, adj[u].size() - 1) {
                int v = adj[u][j].fi;
                if (dist1[v] == i && dist1[v] + dist2[v] == s) /// in floor i-th
                if (adj[u][j].se < _min) {
                    _min = adj[u][j].se;
                    cnt = 1; save[1] = v;
                }
                else if (adj[u][j].se == _min) save[++cnt] = v;
            }
        }
        sort(save+1, save + cnt + 1);
        FOR(i, 1, cnt) if (i == 1 || save[i] != save[i-1]) q.push(save[i]);
        printf("%d ", _min);
    }
    return 0;
}
/** Happy Coding ^^ */
