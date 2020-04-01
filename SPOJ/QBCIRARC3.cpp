#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define taskName "0"

const int N = 1005;
const int M = 2e4 + 5;
vector<int> adj[N];
vector<ii> ans;
ii e[M];
int num[N];
int n, m;

int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
    }

    int minCircle = n+1;

    FOR(u, 1, n) {
        while (!q.empty()) q.pop();
        q.push(u);
        memset(vis, 0, sizeof vis);
        vis[u] = 1;

        int cnt = 1;
        bool cont = 1;

        while (!q.empty() && cont {
            ++ cnt;
            int size = q.size();
            while (cont && (size --)) {
                int v = q.front(); q.pop();
                REP(j, adj[v].size()) {
                    int t = adj[v][j];
                    if (t == u) {
                        if (cnt < minCircle) {
                            minCircle = cnt;
                            REP(i, cnt) {
                                candi[i] = mp(t, par[t])
                            }
                        }
                        cont = 0;
                    } else if (!vis[t]) {
                        vis[t] = 1;
                        q.push(t);
                    }
                }
            }
        }
    }
    return 0;
}
/** Happy Coding :D */
