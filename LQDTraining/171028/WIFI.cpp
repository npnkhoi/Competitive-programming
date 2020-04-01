#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, a[N];

bool ok(int num) {
    int cur = 1, res = 1;

    for (int i = 1; i <= m; i++) {
        if (a[i] - a[cur] > num)
            cur = i, res ++;
    }
    return res <= n;
}
int main() {
    freopen("wifi.inp", "r", stdin);
    freopen("wifi.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
    sort(a+1, a+m+1);
    int l = 0, r = a[m];
    int res = r;
    while (l <= r) {
        int mid = (l+r)/2;
        if (ok(mid)) res = min(res, mid), r = mid - 1;
        else l = mid + 1;
    }
    printf("%d.%d", res/2,res%2*5);
}
