#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = (1 << 17) + 5;

int a[N], before[2][2], after[2][2];

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

        int res = 0;
        FOR(i, 0, 15) {
            FOR(j, i+1, 16) {

                memset(before, 0, sizeof before);
                memset(after, 0, sizeof after);
                
                FOR(k, 1, n) {
                    int num = l - 1 + k;
                    before[((num ^ res) >> i & 1)][((num ^ res) >> j & 1)] ++;
                    after[(a[k] >> i & 1)][(a[k] >> j & 1)] ++;
                    // cerr << "after a[k]: " << a[k] << '\n';
                    // FOR(u, 0, 1) FOR(v, 0, 1) {
                    //     cerr << before[u][v] << ' ' << after[u][v] << '\n';
                    // }
                }

                // cerr << "ij: " << i << ' ' << j << '\n';
                // FOR(u, 0, 1) FOR(v, 0, 1) {
                //     cerr << before[u][v] << ' ' << after[u][v] << '\n';
                // }

                FOR(mask, 0, 3) {
                    bool flag = false;
                    
                    FOR(u, 0, 1) FOR(v, 0, 1) {
                        int z = u ^ (mask >> 1), t = v ^ (mask & 1);
                        if (before[u][v] != after[z][t]) {
                            flag = true;
                        }
                    }

                    if (!flag) {
                        // cerr << i << ' ' << j << ' ' << mask << '\n';
                        res |= (mask >> 1 << i) | (mask & 1 << j);
                        break;
                    }
                }
            }
        }
        cout << res << '\n';
    }
}