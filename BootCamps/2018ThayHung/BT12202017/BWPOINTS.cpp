#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
int n, pre0, pre1, dp[N];
pair<int, int> a[N];
#define fi first
#define se second
#define task "bwpoints"
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].fi);
        a[i].se = 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[n+i].fi);
        a[n+i].se = 1;
    }
    sort(a+1, a+n+n+1);
    pre0 = pre1 = 0;
    for (int i = 1; i <= n+n; i++) {
        if (a[i].se == 1 && pre0 > 0)
            dp[i] = max(dp[i-1], dp[pre0 - 1] + 1);
        else if (a[i].se == 0 && pre1 > 0)
            dp[i] = max(dp[i-1], dp[pre1 - 1] + 1);
        if (a[i].se == 0) pre0 = i;
        else pre1 = i;
    }
    printf("%d", dp[2*n]);
}
