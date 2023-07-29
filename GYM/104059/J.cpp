#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
string s;
int n, dp[N][1 << 4][4];
map <char, int> idx;

void upd(int &a, int b) {
    if (a == -1) {
        a = b;
    } else a = min(a, b);
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("J.inp", "r", stdin);

    idx['h'] = 0;
    idx['d'] = 1;
    idx['c'] = 2;
    idx['s'] = 3;

    cin >> s;
    n = s.size();
    s = ' ' + s;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 4; ++i) {
        dp[0][0][i] = 0;
    }
    int res = n;
    for (int i = 0; i <= n; ++i) {
        for (int mask = 0; mask < (1 << 4); ++mask) {
            for (int cur = 0; cur < 4; ++cur) if (~dp[i][mask][cur]) {
                int cur_op = dp[i][mask][cur];
                if (i == n) {
                    upd(res, cur_op);
                }
                int nxt = idx[s[i + 1]];
                if (nxt == cur) {
                    upd(dp[i + 1][mask][cur], cur_op);
                } else upd(dp[i + 1][mask][cur], cur_op + 1);

                for (int nxt_char = 0; nxt_char < 4; ++nxt_char) {
                    if (mask & (1 << nxt_char))
                        continue;
                    if (nxt_char == cur)
                        continue;
                    upd(dp[i + 1][mask ^ (1 << cur)][nxt_char],
                        cur_op + 1 - (nxt == nxt_char));
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}
