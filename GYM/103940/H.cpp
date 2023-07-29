#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int a[N], n, x;
long long f[(1 << 20) + 2];

int myLog(int x) {
    if (x == 1) return 0;
    else return 1 + myLog(x / 2);
}

long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

int main() {
    // freopen("H.inp", "r", stdin);
    cin >> n >> x;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    f[0] = 1;
    long long res = 0;
    for (int mask = 1; mask < (1 << n); ++ mask) {
        int one = mask & (-mask);
        f[mask] = lcm(f[mask ^ one], a[myLog(one)]);
        int sign = (__builtin_popcount(mask) % 2 == 1 ? 1 : -1);
        res += x / f[mask] * sign;
    }
    cout << res;
}
