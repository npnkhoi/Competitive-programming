#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair< pair<int, int>, int> pack;
const int N = 3e5 + 5;
pack a[N];
int n, save, maxR = 0;
bool cmp(pack a, pack b) {
    if (a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
    return a.fi.se > b.fi.se;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].fi.fi, &a[i].fi.se);
        a[i].se = i;
    }
    sort(a + 1,  a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (a[i].fi.se <= maxR) {
            printf("%d %d", a[i].se, save);
            exit(0);
        }
        if (a[i].fi.se > maxR) {
            maxR = a[i].fi.se;
            save = a[i].se;
        }
    }
    printf("-1 -1");
}
