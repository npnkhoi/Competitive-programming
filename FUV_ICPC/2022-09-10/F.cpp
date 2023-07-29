#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int f(int n) {
    int res = 0;
    while (n > 0) {
        res += n;
        n /= 10;
    }
    return res;
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc -- ) {
        int l, r;
        cin >> l >> r;
        cout << f(r) - f(l) << '\n';
    }
}