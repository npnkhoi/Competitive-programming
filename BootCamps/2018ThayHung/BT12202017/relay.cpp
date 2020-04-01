#include <cstdio>
#include <algorithm>
using namespace std;
#define task "relay"
const int N = 1e5 + 5;
const long long oo = 1e18 + 7;

struct VDV{
    int l, r, t;
};
bool cmp(VDV a, VDV b) {
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}
int n, k;
VDV a[N];
long long dp[N];

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)  {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
    }
    a[0].l = a[0].r = a[0].t = 0;
    a[n+1].l = k;

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = oo;
        for (int j = 0; j < i; j++)
            if (a[j].l <= a[i].l && a[i].l <= a[j].r)
                dp[i] = min(dp[i], dp[j] + 1LL * a[j].t * (a[i].l - a[j].l));
    }
    printf("%lld", dp[n+1]);
}
