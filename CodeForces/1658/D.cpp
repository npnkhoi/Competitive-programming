#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = (1 << 17) + 5;

int a[N];
bool mark[N];

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int tc;
    cin >> tc;
    while (tc --) {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;
        FOR(i, 1, n) {
            cin >> a[i];
        }

        int before = 0, after = 0;
        if (n % 2) {
            FOR(i, 1, n) {
                before ^= (l - 1 + i);
                after ^= a[i];
            }
            cout << (before ^ after) << '\n';
        } else {
            int x = 0;
            FOR(i, 0, 16) {
                before = 0; after = 0;
                FOR(j, 1, n) {
                    before += ((l - 1 + j) >> i & 1);
                    after += (a[j] >> i & 1);
                }
                // cerr << i << ' ' << before << ' ' << after << '\n';
                x |= ((before != after) << i);
            }

            FOR(i, 0, 15) {
                FOR(j, i+1, 16) {
                    
                }
            }

            cout << x << '\n';
        }
    }
}