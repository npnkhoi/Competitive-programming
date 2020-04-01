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
const int N = 3e5 + 5;
const long long md = 1e9 + 7;
int n, q, type, v, x, idx, num[N], tail[N], dep[N];
long long k, ft1[N], ft2[N];
vector<int> adj[N];
void dfs(int u, int h) {
    num[u] = tail[u] = ++idx;
    dep[u] = h;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (num[v] == 0) dfs(v, h+1), tail[u] = tail[v];
    }
}
void adjust(long long ft[], int p, long long val) {
    for (; p <= n; p += p&(-p)) ft[p] = (ft[p] + val) % md;
}
long long rsq(long long ft[], int p) {
    long long res = 0;
    for (; p; p -= p&(-p)) res = (res + ft[p]) % md;
    return res;
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    FOR(i, 2, n) {
        int u;
        scanf("%d", &u);
        adj[u].push_back(i);
    }
    dfs(1, 0);
    scanf("%d", &q);
    while (q --) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %lld", &v, &x, &k);
            adjust(ft1, num[v], x + 1LL * dep[v] * k);
            adjust(ft1, tail[v] + 1, - (x + 1LL * dep[v] * k));
            adjust(ft2, num[v], k);
            adjust(ft2, tail[v] + 1, - k);
        }
        else {
            scanf("%d", &v);
            ll res = (rsq(ft1, num[v]) - rsq(ft2, num[v]) * dep[v]) % md;
            if (res < 0) res = md + res;
            printf("%lld\n", res);
        }
    }
    return 0;
}
/** Happy Coding ^^ */
