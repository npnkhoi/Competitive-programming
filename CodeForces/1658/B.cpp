#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int md = 998244353;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "0\n";
            continue;
        }
        long long res = 1;
        FOR(i, 2, n/2) {
            res = res * i % md;
        }
        res = res * res % md;
        cout << res << '\n';
    }
}