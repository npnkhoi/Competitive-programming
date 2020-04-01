#include <bits/stdc++.h>
using namespace std;
#define task "kuh"

const int N = 105;
int n, m;
int need[N], avai[N], s1[N], s2[N], p1[N], p2[N];
int calc(int i, int s) {
    if (s <= 0) return 0;

    int res = (s + s1[i] - 1) / s1[i] * p1[i], tmp = 0;
    while (s > 0) {
        tmp += p2[i];
        s -= s2[i];
        if (s <= 0) res = min(res, tmp);
        else res = min(res, tmp + (s + s1[i] - 1) / s1[i] * p1[i]);
    }
    return res;
}

int cost(int x) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += calc(i, x * need[i] - avai[i]);
    }
    return res;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d%d%d", &need[i], &avai[i], &s1[i], &p1[i], &s2[i], &p2[i]);
    }
    int l = 0, r = m, res = l;
    while (l <= r) {
        int mid = (l + r) / 2;
        //cerr << cost(mid) << " " << m << "\n";
        if (cost(mid) <= m) {
            res = max(res, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d", res);
}
/// Expelliarmus !
