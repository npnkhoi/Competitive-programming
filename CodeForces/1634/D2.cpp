#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int query(int i, int j, int k) {
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc, n;
    cin >> tc;
    while (tc --) {
        cin >> n;
        int best = query(1, 2, 3), x = 3, y;
        bool flag = false;
        FOR(i, 4, n) {
            int res = query(1, 2, i);
            if (res > best) {
                flag = true;
                best = res;
                x = i;
            }
        }
        if (!flag) {
            cout << "! 1 2" << endl;
            continue;
        }

        // x can be min or max
        
        y = 2; flag = false;
        FOR(i, 3, n) {
            int res = query(1, x, i);
            if (res > best) {
                best = res;
                y = i;
                flag = true;
            }
        }
        if (!flag) {
            cout << "! 1 " << x << endl;
            continue;
        }

        cout << "! " << x << ' ' << y << endl;
    }
}