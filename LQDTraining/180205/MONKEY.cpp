#include <cstdio>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second
const int N = 105;
int t, m, n;
ii a[N], b[N];

long long calc(ii a[], int n, int t) {
    long long res = 0;
    for (int i = 1; i <= n; i++) if (t >= a[i].fi)
        res += 1 + (t - a[i].fi) / a[i].se;
    return res;
}
int main() {
    freopen("monkey.inp", "r", stdin);
    freopen("monkey.out", "w", stdout);
    scanf("%d", &t);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].fi, &a[i].se);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d %d", &b[i].fi, &b[i].se);

    int l = 0, r = t, res = 0;
    //cerr << calc(a, n, 11) << " " << calc(a, n, 13) << "\n";
    //cerr << calc(b, m, 20 - 11) << " " << calc(b, m, 20 - 13) << "\n";
    while (l <= r) {
        int mid = (l + r) / 2;
        if (calc(a, n, mid) <= calc(b, m, t - mid)) {
            res = max(res, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d", res);
}
