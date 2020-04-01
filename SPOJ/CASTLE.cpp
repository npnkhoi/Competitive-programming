#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
#define fi first
#define se second
const int N = 5005;
pair<long long, long long> p[N];
int n, m, head[N], tmp[N];
long long rects, cntMax, cntMin;
unsigned long long minS, maxS;
int main() {
    freopen("castle.inp", "r", stdin);
    freopen("castle.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].fi, &p[i].se);
    sort(p+1, p+n+1);
    m = 1;
    for (int i = 2; i <= n; i++) if (p[i] != p[i-1])
        p[++m] = p[i];
    n = m; m = 0;
    for (int i = 1; i <= n; i++) cerr << p[i].fi << " " << p[i].se << "\n";
    for (int i = 1; i <= n; i++)
        if (i == 1 || p[i].fi != p[i-1].fi)
            head[m++] = i;
    head[m] = n+1;

    for (int i = 0; i <= m - 2; i++)
    for (int j = i+1; j <= m - 1; ++j) {
        cerr << "**" << i << " " << j << "\n";
        //cerr << "-- " << head[i] << " " << head[j] << "\n";
        unsigned long long distX = p[head[j]].fi - p[head[i]].fi;
        int u = head[i], v = head[j];
        int cnt = 0;
        while (u < head[i+1] && v < head[j+1]) {
            while (v < head[j+1] && p[v].se < p[u].se) v++;
            if (v < head[j+1] && p[v].se == p[u].se) tmp[++cnt] = p[u].se;
            //cerr << u << " " << v << "\n";
            u ++;
        }
        rects += 1LL * (cnt - 1) * cnt / 2;
        cerr << cnt << "\n";
        if (cnt > 1) {
            //cerr << p[head[i]].fi << " " << p[head[j]].fi << " " << cnt << "\n";
            unsigned long long foo = distX * (tmp[cnt] - tmp[1]);
            if (foo > maxS) {
                maxS = foo;
                cntMax = 1;
            } else if (foo == maxS)
                cntMax ++;

            for (int i = 1; i < cnt; i++) {
                foo = distX * (tmp[i+1] - tmp[i]);
                if (minS == 0 || foo < minS) {
                    minS = foo;
                    cntMin = 1;
                } else if (foo == minS)
                    cntMin ++;
            }
        }
    }
    printf("%lld\n", rects);
    if (rects > 0) {
        printf("%llu %lld\n", maxS, cntMax);
        printf("%llu %lld\n", minS, cntMin);
    }
}
