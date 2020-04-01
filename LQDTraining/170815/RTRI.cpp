using namespace std;
#include <stdio.h>
#include <utility>
#define fi first
#define se second
const int N = 1e5 + 10;
long long cntX[N], cntY[N];
int n;
pair<int, int> p[N];
int main() {
    freopen("rtri.inp", "r", stdin);
    freopen("rtri.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].fi, &p[i].se);
        cntX[p[i].fi] ++;
        cntY[p[i].se] ++;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) res += (cntX[p[i].fi] - 1)*(cntY[p[i].se] - 1);
    printf("%lld", res);

}
