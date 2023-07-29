#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;
int dp[N][2][2][2];
string L, R;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("H.inp", "r", stdin);

    for (int l = 1; l <= 80000; ++l) {
        for (int r = l; r <= 100000; ++r) {

            L = to_string(l), R = to_string(r);
            cin >> L >> R;
            /*int correct = 0;
            for (int i = l; i <= r; ++i) {
                correct = max(correct, prod(i));
            }*/

            if (L.size() > R.size()) {
                cout << 0 << endl;
                return 0;
            }

            string prev = "";
            while (L.size() + prev.size() < R.size()) {
                prev += "0";
            }
            L = prev + L;

            int n = L.size();
            L = ' ' + L;
            R = ' ' + R;

            if (L > R) {
                cout << 0 << endl;
                return 0;
            }

            for (int i = 1; i <= n; ++i) {
                memset(dp[i], 0, sizeof dp[i]);
            }

            dp[0][0][0][0] = 1;
            int res = 0;
            for (int i = 1; i <= n; ++i) {
                for (int flag1 = 0; flag1 < 2; ++flag1) {
                    for (int flag2 = 0; flag2 < 2; ++flag2)
                        for (int trailing = 0; trailing < 2; ++trailing){
                            int r1 = (flag1 ? 1 : L[i] - '0');
                            int r2 = (flag2 ? 9 : R[i] - '0');
                            if (trailing == 0) {
                                if (!flag1 && L[i] - '0' != 0) {
                                    continue;
                                }
                            }

                        for (int num = r1; num <= r2; ++num) {
                            int nu = num;
                            if (num == 0 && trailing == 0) nu = 1;

                            int &cur = dp[i][flag1][flag2][trailing];
                            cur = max(cur, dp[i - 1][flag1][flag2][trailing] * nu % MOD);
                            bool ok1 = (flag1 && num > L[i] - '0');
                            if (ok1) {
                                cur = max(cur, dp[i - 1][flag1 ^ 1][flag2][trailing] * nu % MOD);
                            }
                            bool ok2 = (flag2 && num < R[i] - '0');
                            if (ok2) {
                                cur = max(cur, dp[i - 1][flag1][flag2 ^ 1][trailing] * nu % MOD);
                            }
                            bool ok3 = trailing;
                            if (ok3) {
                                cur = max(cur, dp[i - 1][flag1][flag2][trailing ^ 1] * nu % MOD);
                            }
                            if (ok1 && ok2) {
                                cur = max(cur, dp[i - 1][flag1 ^ 1][flag2 ^ 1][trailing] * nu % MOD);
                            }
                            if (ok1 && ok3) {
                                cur = max(cur, dp[i - 1][flag1 ^ 1][flag2][trailing ^ 1] * nu % MOD);
                            }
                            if (ok2 && ok3) {
                                cur = max(cur, dp[i - 1][flag1][flag2 ^ 1][trailing ^ 1] * nu % MOD);
                            }
                            if (ok1 && ok2 && ok3) {
                                cur = max(cur, dp[i - 1][flag1 ^ 1][flag2 ^ 1][trailing ^ 1] * nu % MOD);
                            }

                            if (i == n) {
                                res = max(res, cur);
                            }
                        }
                    }
                }
            }


            cout << res << endl;

            return 0;
        }
    }

    return 0;
}
