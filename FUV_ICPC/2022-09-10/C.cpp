#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;

    while (tc --) {
        int n, m;
        cin >> n >> m;
        
        int s = 0, minAbs = 200, countNeg = 0, x;
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                cin >> x;
                s += abs(x);
                minAbs = min(minAbs, abs(x));
                countNeg += (x < 0);
            }
        }
        // cout << "s before: " << s << '\n';
        if (countNeg % 2 == 1) s -= 2 * minAbs;
        cout << s << '\n';
    }
}