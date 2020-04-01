#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

#define debug(x) cerr << #x << ": " << x << "\n"
#define task "visitors"

const int N = 1e5 + 5;
const long long oo = 1e15 + 7;
int a[N], b[N], id[N], pos[N], n;
long long s[N], dp[N], ITLes[4*N], ITGre[4*N], lazyLes[8*N], lazyGre[8*N];
long long remote(int i, int j) {
    if (j <= n) return abs(a[j] - a[i]);
    else return 0;
}
void sub1() {
    for (int i = 1; i <= n; i++) {
        dp[i] = s[i];
        if (i < n) dp[i] += abs(a[i+1]);
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(s[i] - s[j+1]) + remote(j, i+1));
        }
        printf("dp[%d] = %lld\n", i, dp[i]);
    }
    printf("%lld\n", dp[n]);
}
void lazyDown(long long IT[], long long lazy[], int p, int l, int r) {
    lazy[2*p] += lazy[p];
    lazy[2*p+1] += lazy[p];
    IT[p] += lazy[p];
    lazy[p] = 0;
}
void update(long long IT[], long long lazy[], int p, int l, int r, int L, int R, long long val) {
    //printf("update %d %d, %lld\n", L, R, val);
    if (l > r || L > R || l > R || L > r) return;
    lazyDown(IT, lazy, p, l, r);
    if (L <= l && r <= R) {
        IT[p] += val;
        lazy[2*p] += val;
        lazy[2*p+1] += val;
    } else {
        int mi = (l+r) / 2;
        update(IT, lazy, 2*p, l, mi, L, R, val);
        update(IT, lazy, 2*p+1, mi+1, r, L, R, val);
        IT[p] = min(IT[2*p], IT[2*p+1]);
    }
}
long long query(long long IT[], long long lazy[], int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r)  return 10*oo;
    lazyDown(IT, lazy, p, l, r);
    if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r)/2;
        long long x = query(IT, lazy, 2*p, l, mi, L, R);
        long long y = query(IT, lazy, 2*p+1, mi+1, r, L, R);
        return min(x, y);
    }
}
void show(long long IT[], long long lazy[], int p, int l, int r) {
    printf("(%d - %d): %lld %lld\n", l, r, IT[p], lazy[p]);
    if (l < r) {
        show(IT, lazy, 2*p, l, (l+r)/2);
        show(IT, lazy, 2*p+1, 1 +(l+r)/2, r);
    }
}
void sub2() {
    for (int i = 0; i <= n; i++) id[i] = i;
    sort(id, id + n + 1, [](int i, int j) {return a[i] < a[j];});
    for (int i = 0; i <= n; i++) pos[id[i]] = i;
    for (int i = 1; i <= 4 * n + 4; ++i) ITLes[i] = ITGre[i] = oo;
    for (int i = 0; i <= n; i++) cerr << a[i] << " " << pos[i] << "\n";

    dp[0] = abs(a[1]);
    update(ITLes, lazyLes, 1, 0, n-1, pos[0], pos[0], -oo + dp[0]);
    update(ITGre, lazyGre, 1, 0, n-1, pos[0], pos[0], -oo + dp[0]);
    for (int i = 1; i < n; i++) {
            update(ITLes, lazyLes, 1, 0, n-1, 0, n-1, b[i]);
            update(ITLes, lazyLes, 1, 0, n-1, pos[i-1], pos[i-1], -b[i]);
            update(ITGre, lazyGre, 1, 0, n-1, 0, n-1, b[i]);
            update(ITGre, lazyGre, 1, 0, n-1, pos[i-1], pos[i-1], -b[i]);
            cerr << "pre update\n";
            //show(ITLes, lazyLes, 1, 0, n-1);
            //show(ITGre, lazyGre, 1, 0, n-1);
            for (int i = 0; i < n; i++) cerr << query(ITLes, lazyLes, 1, 0, n-1, i, i) << " "; cerr << "\n";
            for (int i = 0; i < n; i++) cerr << query(ITGre, lazyGre, 1, 0, n-1, i, i) << " "; cerr << "\n";
        int x =  upper_bound(id, id + n, i+1, [](int i, int j) {return a[i] < a[j];}) - id;
        debug(a[i+1]); debug(x);
        dp[i] = min(query(ITLes, lazyLes, 1, 0, n-1, 0, x-1) + a[i+1], query(ITGre, lazyGre, 1, 0, n-1, x, n-1) - a[i+1]);
        cerr << query(ITLes, lazyLes, 1, 0, n-1, 0, x-1) << " " << query(ITGre, lazyGre, 1, 0, n-1, x, n-1) << "\n";
        cerr << query(ITLes, lazyLes, 1, 0, n-1, 0, x-1) + a[i+1] << " " << query(ITGre, lazyGre, 1, 0, n-1, x, n-1) - a[i+1] << "\n";
        printf(" *** dp[%d] = %lld\n", i, dp[i]);
        //for (int i = 0; i < n; i++) cerr << query(ITLes, lazyLes, 1, 0, n-1, i, i) << " "; cerr << "\n";
        update(ITLes, lazyLes, 1, 0, n-1, pos[i], pos[i],
            - query(ITLes, lazyLes, 1, 0, n-1, pos[i], pos[i]) + dp[i] - a[i] - s[i+1]);
        update(ITGre, lazyGre, 1, 0, n-1, pos[i], pos[i],
            - query(ITGre, lazyGre, 1, 0, n-1, pos[i], pos[i]) + dp[i] + a[i] - s[i+1]);
        /*cerr << "IT status\n";
        for (int i = 0; i < n; i++) cerr << query(ITLes, lazyLes, 1, 0, n-1, i, i) << " "; cerr << "\n";
        for (int i = 0; i < n; i++) cerr << query(ITGre, lazyGre, 1, 0, n-1, i, i) << " "; cerr << "\n";*/
    }
    dp[n] = oo;
    for (int i = 0; i < n; i++) dp[n] = min(dp[n], dp[i] + s[n] - s[i+2]);
    printf("%lld", dp[n]);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = abs(a[i] - a[i-1]);
        s[i] = s[i-1] + b[i];
    }
    sub1();
}
