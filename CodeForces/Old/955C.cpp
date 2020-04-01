#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
ll v[(int)1e7];
int p, q;

void preCalc() {
    ll U = 1e18;
    int q = 0;
    for (ll i = 2; i <= 1e6; i++) {
        for (ll j = i * i * i; j <= U; j *= i) {
            v[++q] = j;
            //cerr << j << "\n";
            if (j > (U + i - 1)/ i) break;
        }
    }
    sort(v + 1, v + q + 1);
    //cerr << q << "\n";
    p = 0;
    for (int i = 1; i <= q; i++) if (i == 1 || v[i] != v[i-1]) {
        ll u = sqrt(v[i]);
        if (v[i] == u * u) continue;
        v[++p] = v[i];
    }
    //cerr << p << "\n";
}

ll _sqrt(ll x) {
    int l = 0, r = (int) 1e9, res = l;
    while (l <= r) {
        ll mid = (l+r) / 2;
        if (mid * mid <= x) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return res;
}

ll f(ll x) {
    return _sqrt(x) + (upper_bound(v + 1, v + p + 1, x) - v - 1);
}

int main() {
    preCalc();

    int q;
    scanf("%d", &q);
    while (q--) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", f(r) - f(l-1));
    }
}
