#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 5005;

vector<int> adj[N];
long long f[N][N], sum[N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++ i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    f[0][1] = 1;
    sum[0] = 1;

    for (int i = 1; i <= k + 1; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            long long ans = sum[i-1];
            for (int k : adj[j]) {
                ans = (ans + MOD - f[i-1][k]) % MOD;
            }
            ans = (ans + MOD - f[i-1][j]) % MOD;
            f[i][j] = ans;
            sum[i] = (sum[i] + ans) % MOD;
        }
    }
    cout << f[k][1];
}