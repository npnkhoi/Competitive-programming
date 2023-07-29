#include <bits/stdc++.h>

using namespace std;

const int N = 32;
int dp[N][2];

int solve(int x) {
    if (x == -1) {
        return 0;
    }
    memset(dp, 0, sizeof dp);
    int msb = 31 - __builtin_clz(x);
    int len = (msb - 1) / 2;
    bool sm = false;
    for (int i = msb - len; i <= msb; ++i) {
        int j = msb - i;
        int a = (x & (1 << i)) > 0;
        int b = (x & (1 << j)) > 0;
        if (a < b) {
            sm = true;
            break;
        } else if (a > b) {
            break;
        }
        if (i == msb) {
            sm = true;
        }
    }
    dp[msb][0] = 1;
    for (int i = msb - 1; i >= 0; --i) {
        for (int flag = 0; flag < 2; ++flag) {
            dp[i][flag] = dp[i + 1][flag] * (flag + 1);
            if (flag == 1 && (x & (1 << i))) {
                dp[i][flag] += dp[i + 1][flag ^ 1];
            }
        }
    }
    int fac = 1;
    if (msb % 2 == 0 && (x & (1 << (msb - len - 1)))) {
        fac = 2;
    }
    int res = dp[msb - len][1] * ((msb % 2 == 0) ? 2 : 1);
    if (sm) {
        res += dp[msb - len][0] * fac;
    } else {
        res += dp[msb - len][0] * (fac - 1);
    }
    for (int i = msb - 1; i >= 0; --i) {
        int temp = 1 << ((i + 2) / 2 - 1);
        res += temp;
    }
    if (x != 0) {
        res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("B.inp", "r", stdin);

    cerr << solve(-1) << '\n';
    cerr << solve(0) << '\n';
    cerr << solve(2) << '\n';

    return 0;

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        //cerr << solve(l-1) << ' ' << solve(r) << '\n';
        cout << solve(r) - solve(l - 1) << endl;
    }


    return 0;
}
