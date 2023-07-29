#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e6 + 5;
int n, dp[N][3][2];
string s;

void solve(string s) {
    n = s.size();
    s = ' ' + s;
    FOR(i, 0, n) FOR(j, 0, 2) FOR(k, 0, 1) dp[i][j][k] = -1;
    dp[0][0][0] = dp[0][1][0] = 0;
    dp[0][2][0] = dp[0][2][1] = 0;
    FOR(i, 0, n) FOR(type, 0, 2) FOR(parity, 0, 1) {
        if (dp[i][type][parity] == -1) continue;
        int cur = dp[i][type][parity];
        if (parity == 0 || type == 2) {
            FOR(newtype, 0, 2) {
                dp[i + 1][newtype][1] = max(dp[i + 1][newtype][1], cur + 1);
            }
        }
        dp[i + 1][type][parity] = max(dp[i + 1][type][parity], cur);
        dp[i + 1][type][parity ^ 1] = max(dp[i + 1][type][parity ^ 1], cur + 1);
    }
    int res = max(dp[n][0][0], dp[n][1][0]);
    res = max(res, dp[n][2][0]);
    res = max(res, dp[n][2][1]);
    cout << res << endl; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    
    int tc;
    cin >> tc;
    cerr << tc << endl;
    while (tc--) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}