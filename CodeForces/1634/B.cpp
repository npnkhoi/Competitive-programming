#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc, n, x;
    long long y;
    cin >> tc;
    while (tc --) {
        cin >> n >> x >> y;
        int odd = 0, a;
        FOR(i, 1, n) {
            cin >> a;
            odd ^= (a % 2);
        }
        if ((y - x - odd) % 2 == 0) cout << "Alice\n"; 
        else cout << "Bob\n";
    }
}