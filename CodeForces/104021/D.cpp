#include <bits/stdc++.h>
using namespace std;

const int md = 59964251, period = md - 643 - 93257 + 1, M = 1e5 + 5;

string n;
long long m, m2, d, k, nmod, numFacs[M], minPrime[M];
long long sum[M], a[M];

long long Exp(long long a, long long b, long long m) {
    if (b == 0) return 1;
    long long ret = Exp(a, b/2, m);
    ret = ret * ret % m;
    if (b&1) ret = ret * a % m;
    return ret;
}

long long f(int di) {
    // return the
    long long cap = m2 / di;
    return Exp(Exp(di, k, md) * sum[cap] % md, nmod, md);
}

void prep() {
    m2 = m / d;

    for (int i = 1; i <= m; ++ i) {
        sum[i] = (sum[i-1] + Exp(i, k, md)) % md;
    }

    nmod = 0;
    for (int i = 0; i < n.size(); ++i) {
        nmod = (nmod * 10 + (n[i] - '0')) % period;
    }
}

void init() {
    memset(minPrime, -1, sizeof minPrime);
    int lim = 1e5;

    for (int i = 2; i <= lim; i ++) {
        if (minPrime[i] == -1) {
            minPrime[i] = i;
            for (long long j = 1LL * i * i; j <= lim; j += i) {
                if (minPrime[j] == -1) minPrime[j] = i;
            }
        }
    }


    // a bit inefficient
    for (int i = 1; i <= lim; ++ i) {
        set<int> facs;
        int tmp = i;
        while (tmp > 1) {
            int fac = minPrime[tmp];
            facs.insert(fac);
            tmp /= fac;
            if (tmp % fac == 0) {
                // double factor
                numFacs[i] = -1;
                break;
            }
        }
        if (numFacs[i] == 0) numFacs[i] = facs.size();
    }
}

long long bf() {
    long long res = 0;
    int nint = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        nint = nint * 10 + (n[i] - '0');
    }

    for (int mask = 0; mask < Exp(m, nint, 1e9); mask ++) {
        int tmp = mask;
        for (int i = 1; i <= nint; ++ i) {
            a[i] = (tmp % m) + 1;
            tmp /= m;
        }
        tmp = a[1];
        for (int i = 2; i <= nint; ++ i) tmp = __gcd(1LL * tmp, a[i]);
        // for (int i = 1; i <= nint; ++ i) cerr << a[i] << ' '; cerr << '\n';
        // cerr << "gcd = " << tmp << '\n';
        if (tmp == d) {
            long long s = 1;
            for (int i = 1; i <= nint; ++ i) {
                s = s * Exp(a[i], k, md) % md;
            }
            // cerr << "s = " << s << '\n';
            res = (res + s) % md;
        }
    }
    return res;
}

int getRand(int l, int r) {
    return l + rand() % (r - l + 1);
}

void genTest() {
    n = to_string(getRand(1, 5));
    m = getRand(1, 10);
    d = getRand(1, 7);
    k = getRand(1, 1e9);
}

int main() {
    // freopen("D.inp", "r", stdin);
    // srand(time(NULL));
    init();

    int tc; cin >> tc;

    while (tc --) {
        cin >> n >> m >> d >> k;
        // genTest();


        prep();

        // additions
        long long res = 0;
        for (int di = 1; di <= m2; di ++) {
            if (numFacs[di] == -1) continue;
            // cerr << "di = " << di << '\n';
            res = (res + f(di) * (numFacs[di] % 2 == 0 ? +1 : -1) + md) % md;
            // cerr << "numFacs[di] = " << numFacs[di] << '\n';
            // cerr << "res = " << res << '\n';
        }
        // cerr << "after adds: " << res << '\n';
        // mul
        res = res * Exp(d, k * nmod % period, md) % md;
        cout << res << '\n';
        /*
        // cerr << n << ' ' << m << ' ' << d << ' ' << k << '\n';
        long long ans = bf();
        if (res != ans) {
            cerr << "WRONG HERE! " << ans;
        } else {
            cerr << "CORRECT\n";
        }
        */
    }
}
