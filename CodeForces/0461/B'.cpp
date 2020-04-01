using namespace std;
#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
const int N = 1e5 + 10;
const long long md = 1e9 + 7;
vector<int> adj[N];
int color[N], n, par[N], black[N];
bitset<N> sign;
long long dp[N][2];
ll Pow(ll a, ll x) {
    if (x == 1) return a % md;
    ll p = Pow(a, x/2) * Pow(a, x/2) % md;
    if (x&1) p = p * a % md;
    return p;
}
void dfs(int u) {
    sign[u] = 1;
    black[u] = (color[u] == 1);

    if (color[u] == 1) {
        dp[u][0] = 0; // fixed
        dp[u][1] = 1;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (!sign[v]) {
                dfs(v);
                if (black[v] != 0) dp[u][1] = dp[u][1] * (dp[v][1] + dp[v][0]) % md;
                black[u] += black[v];
            }
        }
    }
    else {
        dp[u][0] = 1;
        ll p = 1, t = 0, cnt = 0;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (!sign[v]) {
                dfs(v);
                black[u] += black[v];
                if (black[v] != 0) {
                    dp[u][0] = dp[u][0] * (dp[v][1] + dp[v][0]) % md;
                    t = t*(dp[v][0] + dp[v][1]) % md;
                    t = (t + p * dp[v][1]) % md;
                    p = p * (dp[v][0] + dp[v][1]) % md;
                    cnt ++;
                }
            }
        }
        dp[u][1] = t;
        //dp[u][0] = dp[u][0] * cnt % md;
        /*dp[u][1] = t;
        if (adj[u].size() > 1 && dp[u][1] == 0) dp[u][1] = 1;*/
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x; scanf("%d", &x);
        adj[i].pb(x);
        adj[x].pb(i);
    }
    for (int i = 0; i < n; i++) scanf("%d", &color[i]);
    dfs(0);
    //for (int i = 0; i < n; i++)
    //cout << i << ": " << black[i] << " " << dp[i][0] << " " << dp[i][1] << endl;
    printf("%lld", dp[0][1]);
}
