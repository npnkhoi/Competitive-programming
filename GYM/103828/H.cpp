#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << 0 << endl;
            continue;
        } else {
            int pairs = (n - 2) / 2;
            int res = pairs * n / 2;
            if ((n - 2) / 2) & 1) {
                res -= n / 4;
            }
            cout << res << endl;
        }
    }
}
