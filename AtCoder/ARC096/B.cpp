#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long c, res, a[N], l[N], r[N], mx[N];
int n, v[N];
long long calc() {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        l[i] = l[i-1] - 2 * (a[i] - a[i-1]) + v[i];
        mx[i] = max(mx[i-1], l[i]);
    }
    for (int i = n; i >= 1; --i) {
        r[i] = r[i+1] - (a[i+1] - a[i]) + v[i];
        ans = max(ans, mx[i-1] + r[i]);
    }
    return ans;
}
int main() {
    scanf("%d%lld", &n, &c);
    a[n+1] = c;
    for (int i = 1; i <= n; ++i) scanf("%lld%d", &a[i], &v[i]);
    res = calc();
    for (int i = 1; i <= n; i++) a[i] = c - a[i];
    for (int i = 1; i <= n / 2; i ++) {
        int j = n - i + 1;
        swap(a[i], a[j]);
        swap(v[i], v[j]);
    }
    res = max(res, calc());
    printf("%lld", res);
}
