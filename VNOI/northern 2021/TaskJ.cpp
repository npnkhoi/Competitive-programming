#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
int n, m, a[N], b[N];

bool check(int mid) {
    int sum = 0;
    for (int i= 1; i <= n; ++i) {
        if (a[i] >= (int)1e16 / b[i] && (mid / (b[i] + 1)) >= 1) return true;

        int prod = a[i] * b[i], times = (mid / (b[i] + 1));
        if (times >= (int)1e16 / prod && times >= 1) return true;
        if ((mid % (b[i] + 1)) >= (int)1e16 / a[i]) return true;
        sum += (mid / (b[i] + 1)) * prod + (mid % (b[i] + 1)) * a[i];
        if (sum >= (int)1e16) return true;
    }
    // cerr << mid << ' ' << sum << endl;
    if (sum >= m) return true;
    else return false;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> m;
    
    for (int i= 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    int l = 1, r = (int)1e15, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    cout << ans << endl;

    return 0;
}  