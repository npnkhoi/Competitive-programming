#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("G.inp", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int pre = 0, sum = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            pre -= sum;
            pre = (pre + MOD) % MOD;
            sum += 1LL * i + 1;
            sum %= MOD;
            int v = s.size() - i;
            pre += v * (v + 1) / 2;
            pre %= MOD;
            res += pre * (s[i] - 'a' + 1);
            res %= MOD;
        }
        cout << res << endl;
    }

}
