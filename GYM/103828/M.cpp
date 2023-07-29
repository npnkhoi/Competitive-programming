#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int x, y;
        cin >> x >> y;
        int l = 0, r = (int)2e9;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid * (mid + 1) / 2 >= x + y) {
                r = mid - 1;
                ans = mid;
            } else l = mid + 1;
        }
        cout << ans << endl;
    }
}
