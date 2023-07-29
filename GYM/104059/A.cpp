#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define int long long
using namespace std;

signed main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    int res = 1;
    a--; b--;
    for (int x = 1; x <= a - 1; x++) {
        int y2 = a*a - x*x;
        int y = floor(sqrt(y2));
        if (y * y != y2) continue;
        if (b * x % a != 0) continue;
        res ++;
    }
    if (a != b) res += res;
    cout << res << '\n';
}