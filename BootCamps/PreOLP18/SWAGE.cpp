#include <cstdio>
#include <utility>
#include <algorithm>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
const int N = 2e3 + 5;

int n, res;
ii a[N], b[N];

bool cmp(ii a, ii b) {
    return 1LL * a.se * b.fi < 1LL * b.se * a.fi;
}
bool Equal(ii a, ii b) {
    return 1LL * a.se * b.fi == 1LL * b.se * a.fi;
}
int main() {
    scanf("%d", &n);
    res = min(2, n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].fi, &a[i].se);
    }
    for (int i = 1; i <= n; i++) {
        int m = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j].se >= a[i].se && i != j) {
                b[++m] = make_pair(a[j].fi - a[i].fi,  a[j].se - a[i].se);
            }
        }
        sort(b+1, b+m+1, cmp);
        int l = 1;
        for (int r = 2; r <= m; r++) {
            if (!Equal(b[r], b[r-1])) l = r;
            else res = max(res, r - l + 2);
        }
    }
    printf("%d", res);
}
