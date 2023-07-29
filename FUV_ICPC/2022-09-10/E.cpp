#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

long long expo(long long a, int deg) {
    long long res = 1;
    FOR(i, 1, deg) res = res * a;
    return res;
}

int getDeg(long long num, int factor) {
    int cnt = 0;
    while (num % factor == 0) {
        cnt ++;
        num /= factor;
    }
    return cnt;
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        long long p, q;
        cin >> p >> q;

        if (p % q != 0 || p < q) {
            cout << p << '\n';
            continue;
        }


        // Now p > q
        // factorize
        long long savedP = p, minCut = p, lim = sqrt(q) + 1;
        for (int k = 2; k <= lim; k ++) {
            if (q % k == 0) {
                int degP = getDeg(p, k), degQ = getDeg(q, k);
                minCut = min(minCut, expo(k, degP - degQ + 1));

                while (p % k == 0) p /= k;
                while (q % k == 0) q /= k;
            }
            if (q > 1) minCut = min(minCut, expo(q, getDeg(p, q)));
        }
        cout << savedP / minCut << '\n';
    }
}