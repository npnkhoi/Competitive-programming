#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LOG = 22;
int a[N][LOG], b[N][LOG];

int getMin(int l, int r) {
    int t = r - l + 1;
    int res = a[r][0];
    for (int j = 0; (1<<j) <= t; j++)
    if (t&(1<<j)) {
        res = min(res, a[r][j]);
        r -= (1<<j);
    }
    return res;
}
int getMax(int l, int r) {
    int t = r - l + 1;
    int res = b[r][0];
    for (int j = 0; (1<<j) <= t; j++)
    if (t&(1<<j)) {
        res = max(res, b[r][j]);
        r -= 1<<j;
    }
    return res;
}
int main() {
    freopen("cow.inp", "r", stdin);
    freopen("cow.out", "w", stdout);
    int n, q, l, r;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][0]);
        b[i][0] = a[i][0];
    }
    for (int j = 1; (1<<j) <= n; j++)
    for (int i = 1<<j; i <= n; i++) {
        a[i][j] = min(a[i][j-1], a[i-(1<<(j-1))][j-1]);
        b[i][j] = max(b[i][j-1], b[i-(1<<(j-1))][j-1]);
    }
    while (q--) {
        scanf("%d%d", &l ,&r);
        printf("%d\n", getMax(l, r) - getMin(l, r));
    }
    return 0;
}
