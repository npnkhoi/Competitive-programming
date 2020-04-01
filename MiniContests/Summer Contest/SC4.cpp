#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "SC4"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 305;
const int oo = 1e9 + 7;
int c[N][N], d[N][N], del[N];
int n;
vi adj[N];
priority_queue<ii, vector<ii>, greater<ii> > heap;
ll ans[N];
vi nodeIn;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d", &n);
        FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &c[i][j]);
        memset(del, 0, sizeof del);
        FOR(i, 1, n) {
            FOR(i, 1, n) FOR(j, 1, n) if (i != j) d[i][j] = c[i][j];
            FOR(k, 1, n) FOR(u, 1, n) FOR(v, 1, n) {
                if (!del[u] && !del[v] && !del[k])
                    d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
            ll res = 0;
            FOR(u, 1, n) FOR(v, 1, n) {
                if (!del[u] && !del[v])
                    res += d[u][v];
            }
            printf("%lld ", res);
            int tmp; scanf("%d", &tmp); del[tmp] = 1;
        }
        printf("\n");
    }
}
