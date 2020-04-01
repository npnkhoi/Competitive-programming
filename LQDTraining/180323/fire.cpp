#include <bits/stdc++.h>
using namespace std;
struct pack {
    int t, d, p;
};
const int N = 105;
const int D = 2005;
pack a[N];
int n, f[D], res;

bool cmp(pack a, pack b) {
    return a.d < b.d;
}
int main() {
    freopen("fire.inp", "r", stdin);
    freopen("fire.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p);
    sort(a+1, a+n+1, cmp);

    for (int i = 1; i <= n; i++)
    for (int j = a[i].d - 1; j >= a[i].t; j--) {
        f[j] = max(f[j], f[j - a[i].t] + a[i].p);
        res = max(res, f[j]);
    }
    printf("%d", res);
}
