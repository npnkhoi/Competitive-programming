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
long long s[N], dp[N], ITLes[4*N], ITGre[4*N];
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
    }
    printf("%lld\n", dp[n]);
}
void update(long long IT[], int p, int l, int r, int idx, long long val) {
    if (l > idx || idx > r) return;
    if (l == idx && idx == r) IT[p] = min(IT[p], val);
    else {
        int mi = (l+r)/2;
        update(IT, 2*p, l, mi, idx, val);
        update(IT, 2*p+1, mi+1, r, idx, val);
        IT[p] = min(IT[2*p], IT[2*p+1]);
    }
}
long long query(long long IT[], int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r)  return oo;
    if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r)/2;
        long long x = query(IT, 2*p, l, mi, L, R);
        long long y = query(IT, 2*p+1, mi+1, r, L, R);
        return min(x, y);
    }
}
void sub2() {
    for (int i = 0; i < n; i++) id[i] = i;
    sort(id, id + n, [](int i, int j) {return a[i] < a[j];});
    for (int i = 0; i < n; i++) pos[id[i]] = i;
    for (int i = 1; i <= 4 * n; ++i) ITLes[i] = ITGre[i] = oo;
    //for (int i = 0; i <= n; i++) cerr << a[i] << " " << pos[i] << "\n";

    dp[0] = abs(a[1]);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int x =  upper_bound(id, id + n, i+1, [](int i, int j) {return a[i] < a[j];}) - id;
            dp[i] = min(query(ITLes, 1, 0, n-1, 0, x-1) + a[i+1] + s[i],
                        query(ITGre, 1, 0, n-1, x, n-1) - a[i+1] + s[i]);
        }
        update(ITLes, 1, 0, n-1, pos[i], dp[i] - s[i+1] - a[i]);
        update(ITGre, 1, 0, n-1, pos[i], dp[i] - s[i+1] + a[i]);
    }
    dp[n] = oo;
    for (int i = 0; i < n; i++) dp[n] = min(dp[n], dp[i] + s[n] - s[i+1]);
    printf("%lld", dp[n]);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = abs(a[i] - a[i-1]);
        s[i] = s[i-1] + b[i];
    }
    //if (n <= 2000) sub1();
    //else sub2();
    sub2();
}
