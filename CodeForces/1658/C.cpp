#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e5 + 5;

int n;
int c[N];

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int tc;
    cin >> tc;
    while (tc --) {
        cin >> n;
        int pos = -1;
        bool flag = false;
        FOR(i, 1, n) {
            cin >> c[i];
            if (c[i] == 1) {
                if (pos == -1) {
                    pos = i;
                } else {
                    flag = true;
                }
            }
        }

        flag |= (pos == -1);

        if (flag) {
            cout << "NO\n";
            continue;
        }

        FOR(i, 1, n-1) {
            int prev = c[pos];

            pos ++;
            if (pos > n) pos -= n;

            if (c[pos] - prev > 1) flag = true;
        }
        cout << (flag ? "NO" : "YES") << '\n';
    }   
}