#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 500;
int n, m;

signed main() {
    freopen("I.txt", "r", stdin);
    cin >> n >> m;
    vector<vector<int>> board;
    board.assign(n + 5, vector<int>(m + 5, -1));
    /*
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << board[i][j] << ' ';
        } cout << endl;
    } */

    vector<int> costList(n + 5);
    for(int i = 1; i <= n; i++) {
        int cost; cin >> cost;
        costList[i] = cost;
        for(int j = 1; j <= min(m, n - i + 1); j++)
            cin >> board[i][j];
    }

    /*
    for(int i = 1; i <= n; i++)
        cout << costList[i] << ' '; cout << endl; */

    vector<int> dp(n + 5, 0);
    for(int i = 1; i <= n; i++) {
        // cerr << "i = " << i << '\n';
        int cur = 1e18;
        // cerr << "cur init = " << cur << "\n";
        for(int j = max(1LL, i - m + 1); j <= i; j++) {
            if(board[j][i - j + 1] == -1) continue;
            // cerr << "considering " << j << '\n';
            // cerr << dp[j - 1] << ' ' << costList[j] << ' ' << board[j][i - j + 1] << '\n';
            cur = min(cur, dp[j - 1] + costList[j] - board[j][i - j + 1]);
        }
        dp[i] = cur;
        // cerr << "dp[i] = " << dp[i] << '\n';
    }

    /*
    for(int i = 0; i <= n; i++)
        cout << dp[i] << ' '; cout << endl; */

    /*
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << board[i][j] << ' ';
        } cout << endl;
    } */
    cout << dp[n];
    return 0;
}
