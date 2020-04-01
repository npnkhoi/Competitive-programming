using namespace std;
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
const int N = 1000 + 5;
int n, m, q, l, r;
long long a[N][N], res;
long long sum(int x, int y, int u, int v) {
    return a[u][v] + a[x-1][y-1] - a[x-1][v] - a[u][y-1];
}
int main() {
    //freopen("MINCUT.INP", "r", stdin);
    //freopen("MINCUT.OUT", "w", stdout);
    scanf("%d %d %d", &m, &n, &q);
    FOR(i, 1, m) FOR(j, 1, n) {
        scanf("%lld", &a[i][j]);
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
    while (q--) {
        int x, y, u, v;
        scanf("%d %d %d %d", &x, &y, &u, &v);
        long long val = sum(x, y, u, v) / 2;
        //------------------------------
        l = y, r = v-1;
        while (l < r) {
            int mi = (l+r+1)/2;
            if (sum(x, y, u, mi) <= val) l = mi;
            else r = mi-1;
        }
        res = abs(sum(x, y, u, v) - 2*sum(x, y, u, l));

        l = y+1, r = v;
        while (l < r) {
            int mi = (l+r)/2;
            if (sum(x, mi, u, v) <= val) r = mi;
            else l = mi+1;
        }
        res = min(res, abs(sum(x, y, u, v) - 2*sum(x, l, u, v)));
        //----------------------------------
        l = x, r = u-1;
        while (l < r) {
            int mi = (l+r+1)/2;
            if (sum(x, y, mi, v) <= val) l = mi;
            else r = mi-1;
        }
        res = min(res, abs(sum(x, y, u, v) - 2*sum(x, y, l, v)));

        l = x+1, r = u;
        while (l < r) {
            int mi = (l+r)/2;
            if (sum(mi, y, u, v) <= val) r = mi;
            else l = mi+1;
        }
        res = min(res, abs(sum(x, y, u, v) - 2*sum(l, y, u, v)));

        printf("%lld\n", res);
    }

}
