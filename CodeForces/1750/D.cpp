#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;


const int MOD = 998244353, N = 2e5 + 5, VAL = 1e7 + 10;

int a[N], n, m, minPrime[VAL];
set<int> factors;

void prepSield() {
    memset(minPrime, -1, sizeof minPrime);
    FOR(i, 2, 1e7) {
        if (minPrime[i] != -1) continue;
        minPrime[i] = i;
        for (long long j = 1LL * i * i; j <= 1e7; j += i) {
            if (minPrime[j] == -1) minPrime[j] = i;
        }
    }
}

int getMinPrime(int x) {
    if (x <= 1e7) return minPrime[x];
    for (long long i = 2; i * i <= x; ++ i) {
        if (x % i == 0) {
            return i;
        }
    }
    if (x > 1) return x;
    return -1;
}

void factorize(int x) {
    // side effect: modify factors
    factors.clear();
    while (true) {
        int tmp = getMinPrime(x);
        // cerr << x << ' ' << tmp << '\n';
        if (tmp == -1) break;
        factors.insert(tmp);
        while (x % tmp == 0) x /= tmp;
    }
}

int numCoPrime(int x, int m) {
    // cerr << x << ' ' << m << '\n';
    // returns the amount of numbers <= m, coprime with x
    vector<int> v;
    for (int p : factors) {
        if (x % p == 0) {
            v.push_back(p);
        }
    }
    // cerr << "v: ";
    // for (auto x : v) cerr << x << ' '; cerr << '\n';
    int t = v.size(), res = 0;
    FOR(mask, 0, ((1 << t) - 1)) {
        int sign = (__builtin_popcount(mask) % 2 == 0 ? +1 : -1);
        int factor = 1;
        FOR(i, 0, t-1) {
            if (mask >> i & 1) factor *= v[i];
        }
        res += sign * (m / factor);
    }
    // cerr << res << '\n';
    return res;
}

int main() {
    prepSield();
    // cerr << "done sield\n";

    // freopen("D.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        cin >> n >> m;
        long long res = 1;
        FOR(i, 1, n) {
            cin >> a[i];
            if (i == 1) {
                // res = m / a[i];
                factorize(a[i]);
                // cerr << "done factorize \n";
            } else {
                if (a[i-1] % a[i] != 0) {
                    res = 0;
                } else if (a[i] < a[i-1]) {
                    res = res * numCoPrime(a[i-1] / a[i], m / a[i]) % MOD;
                } else {
                    res = res * (m / a[i]) % MOD;
                }
            }
        }
        cout << res << '\n';
    }
}