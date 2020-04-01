using namespace std;
#include <bits/stdc++.h>
#define task "colorec"
const int A = 410;
int n, cnt[6][6], color[A+5][A+5];
int minx, maxx, miny, maxy, row[A], col[A];
long long res;
int main() {
    //freopen("in.txt", "r", stdin);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    minx = A; maxx = 0;
    miny = A; maxy = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u += 201;
        v += 201;
        color[u][v] = c;
        row[u] ++;
        minx = min(minx, u);
        maxx = max(maxx, u);
        miny = min(miny, v);
        maxy = max(maxy, v);
    }
    for (int i = minx; i < maxx; i++) if (row[i] >= 2)
    for (int j = i+1; j <= maxx; j++) if (row[j] >= 2) {
        memset(cnt, 0, sizeof cnt);
        for (int k = miny; k <= maxy; k++) {
            int p = color[i][k], q = color[j][k];
            if (p == 0 || q == 0 || p == q) continue;
            if (p > q) swap(p, q);
            cnt[p][q]++;

            int u, v;
            if (p == 1 && q == 2) u = 3, v = 4;
            else if (p == 1 && q == 3) u = 2, v = 4;
            else if (p == 1 && q == 4) u = 2, v = 3;
            else if (p == 2 && q == 3) u = 1, v = 4;
            else if (p == 2 && q == 4) u = 1, v = 3;
            else if (p == 3 && q == 4) u = 1, v = 2;
            res += 1LL * cnt[u][v];
            //printf("%d %d - %d %d\n", p, q, u, v);
        }
    }
    printf("%lld", res);
}
