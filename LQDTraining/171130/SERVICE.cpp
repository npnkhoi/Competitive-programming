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

#define taskName "service"

const int N = 505;
const ll oo = 1e18 + 9;
ll a[N][N];
int m, n, q;
vi tmp;

int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    FOR(i, 1, n) FOR(j, 1, n) a[i][j] = oo;

    while (m--) {
        int u, v;
        ll c;
        scanf("%d%d%lld", &u, &v, &c);
        a[u][v] = min(a[u][v], c);
    }
    while (q --) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            int u;
            scanf("%d", &u);
            /*tmp.pb(u);

            REP(z, tmp.size()) {
                int k = tmp[z];
                FOR(i, 1, n) FOR(j, 1, n) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }*/
            FOR(i, 1, n) FOR(j, 1, n) a[i][j] = min(a[i][j], a[i][u] + a[u][j]);
        } else {
            int u, v;
            scanf("%d%d", &u, &v);
            if (a[u][v] == oo) printf("-1\n");
            else printf("%lld\n", a[u][v]);
        }
    }
    return 0;
}
/** Happy Coding :D */
