using namespace std;
#include <stdio.h>
#include <algorithm>
#define fi first
#define se second
const int N = 1e5 + 50;
int n;
pair<int, int> a[N];
long long res = 0;
int main() {
    freopen("covering.inp", "r", stdin);
    freopen("covering.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].fi, &a[i].se);

    sort(a + 1, a + 1 + n);

    int tmp = 0;

    for (int i = n; i >= 1; i--)
        if (a[i].se > tmp) {
            res += 1LL * (a[i].se - tmp) * a[i].fi;
            tmp = a[i].se;
        }
    printf("%lld", res);
}
