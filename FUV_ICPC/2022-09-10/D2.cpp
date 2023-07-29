#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int f[4][10];

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        int n;
        cin >> n;

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        while (n --) {
            int x;
            cin >> x;
            x = x % 10;
            FORD(row, 2, 0) {
                FORD(col, 9, 0) {
                    if (f[row][col]) {
                        f[row + 1][(col + x) % 10] = 1;
                    }
                }
            }
        }
        cout << (f[3][3] ? "YES" : "NO") << "\n";
    }
}