#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    FOR(test, 1, tc) {
        cin >> n;
        FOR(i, 1, n) {
            cin >> a[i];   
        }
        sort(a+1, a+n+1);
        int res = 0;
        FOR(i, 1, n) {
            if (a[i] >= res + 1) {
                res ++;
            }
        }
        cout << "Case #" << test << ": " << res << '\n';
    }
}