#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, r;
ll k, s[N], t[N], tmp[N];
bool ok(ll x) {
    for (int i = 1; i <= n; i++) t[i] = x - s[i];
    //for (int i = 1; i <= n; i++) cerr << t[i] << "\n"; cerr << "\n";
    memset(tmp, 0, sizeof tmp);

    ll cur = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        cur += tmp[i];
        //cerr << tmp[i] << " " << cur << " ";
        if (cur < t[i]) {
            cnt += t[i] - cur;
            tmp[min(i + 2*r, n) + 1] -= t[i] - cur;
            cur = t[i];
        }
        if (cnt > k) return 0;
        //cerr << cur << " " << cnt << "\n";
    }
    return 1;
}
int main() {
    //freopen("0.in", "r", stdin);
    scanf("%d%d%lld", &n, &r, &k);
    for (int i = 1;  i <= n; i++) {
        int x;
        scanf("%d", &x);
        s[max(i - r, 1)] += x;
        s[min(i + r, n) + 1] -= x;
        //cerr << i << " " << x << "\n";
    }
    for (int i = 2; i <= n; i ++) s[i] += s[i-1];
    //for (int i = 1; i <= n; i++) cerr << s[i] << "\n";
    //cerr << ok(499999999999999999);
    //for (int i = 0; i <= 6; i++) cerr << ok(i) << " "; cerr << "\n";
    ll l = 0, r = 2e18, res = 0;
    while (l <= r) {
        //cerr << l << " " << r << "\n";
        ll mid = (l + r) / 2;
        if (ok(mid)) {
            //cerr << "ok" << mid << "\n";
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%lld", res);
}
