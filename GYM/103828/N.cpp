#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 1e9 + 7;
int fac[N];

int modPow(int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}

int inv(int x) {
    x %= MOD;
    return modPow(x, MOD - 2);
}

int C(int k, int n) {
    if (k < 0 || k > n) {
        return 0;
    }
    int ret = fac[n];
    ret = ret * inv(fac[k] * fac[n - k]) % MOD;
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % MOD;

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m, a, b, k;
        cin >> n >> m >> a >> b >> k;
        int res = 0;
        for (int i = 0; i <= k; ++i) {
            int prob = C(i, k) * inv(modPow(2, k)) % MOD;
            int down = i, left = k - i;
            int pushdown = min(down, n * a) / a, pushleft = min(left, m * b) / b;
            res += (prob * pushdown % MOD) * pushleft % MOD;
            res %= MOD;
        }
        cout << res << endl;
    }
}
