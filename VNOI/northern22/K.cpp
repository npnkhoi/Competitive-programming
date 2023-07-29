#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105;
int n, a[N], dp[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("K.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            int num = 0;
            bool ok = true;
            for (int k = j; k <= i; ++k) {
                if (num != 0 && a[k] != 0 && a[k] != num)
                    ok = false;
                if (a[k] > 0) {
                    num = a[k];
                }
            }
            if (!ok) {
                continue;
            }
            if (num == i - j + 1 || num == 0) {
                dp[i] += dp[j - 1];
            }
            dp[i] = min(dp[i], (int)1e18);
        }
    }

    if (dp[n] == 1) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;

    return 0;
}
