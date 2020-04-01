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

#define taskName "COMMUTE"
const int N = 2e5 + 5;
int n, len[N], start[N], adj[N], g[N];
bool mark[N];
void check(int u, int d) { /// calc len of cycle has u (d: cur len)
    mark[u] = 1;
    int v = adj[u];
    if (mark[v] == 0) {
        check(v, d + 1);
        len[u] = len[v];
    } else len[u] = d;
}
void calc(int x, int y) { /// let g[x] = y;
    if (g[x] == 0) {
        g[x] = y;
        calc(adj[x], adj[y]);
    }
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int val;
        scanf("%d", &val);
        adj[val] = i;
    }
    /// len[u]: length of cycle contains vertex u
    /// start[l]: minimum index of a vertex in a cycle of size l
    FOR(i, 1, n) start[i] = n;
    FOR(i, 1, n) if (mark[i] == 0) {
        check(i, 1);
        start[len[i]] = min(start[len[i]], i);
    }
    FOR(u, 1, n) if (g[u] == 0) {
        int tmp = u;
        for (int i = 1; i * i <= len[u]; i++)
            if (len[u] % i == 0)
            tmp = min(tmp, min(start[i], start[len[u]/i]));
        calc(u, tmp);
    }
    FOR(u, 1, n) printf("%d ", g[u]);
    return 0;
}
/** Happy Coding :D */
