#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
    // freopen("A.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        string a, b;
        int m, n;

        cin >> n >> m;
        cin >> a >> b;

        int p = m - 1;
        bool flag = true;

        FOR(i, 0, p-1) {
            if (a[n-1-i] != b[m-1-i]) flag = false;
        }
        if (!flag) {
            cout << "NO\n";
            continue;
        }
        flag = false;
        FOR(i, 0, n-p-1) {
            if (a[i] == b[0]) flag = true;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}
