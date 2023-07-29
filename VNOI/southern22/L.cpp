#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005;
int n, memo[N][2], dp[N][2];
string a, b, c;

 int calc(int i, int carry) {
    if (i == 1) {
        if (carry == 0) {
            return 0;
        } else return -N;
    }
    if (~memo[i][carry]) {
        return memo[i][carry];
    }
    int res = -N;
    int nxt = (a[i - 1] - '0' + b[i - 1] - '0' + carry) % 10;
    if (nxt == c[i - 1] - '0') {
        res = calc(i - 1, (a[i - 1] - '0' + b[i - 1] - '0' + carry) / 10) + 1;
    }
    res = max(res, calc(i - 1, carry));
    return memo[i][carry] = res;
 }

void solve() {
    cin >> a >> b >> c;
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;

    for (int i = 1; i <= n + 1; ++i) {
        dp[i][0] = dp[i][1] = -N;
    }
    dp[n + 1][0] = 0;
    for (int i = n + 1; i >= 2; --i) {
        for (int carry = 0; carry < 2; ++carry) {
            if (dp[i][carry] < 0) {
                continue;
            }
            int nxt = (a[i - 1] - '0' + b[i - 1] - '0' + carry) % 10;
            int cr = (a[i - 1] - '0' + b[i - 1] - '0' + carry) / 10;
            if (nxt == c[i - 1] - '0') {
                dp[i - 1][cr] = max(dp[i - 1][cr], dp[i][carry] + 1);
            }
            dp[i - 1][carry] = max(dp[i - 1][carry], dp[i][carry]);
        }
    }

    cout << n - dp[1][0] << endl;
}

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("L.inp", "r", stdin);

    while (cin >> n && n) {
        solve();
    }

    return 0;
}
