#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, a[N][N], u, v;
long long x, y, z;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("B.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                u = i, v = j;
            }
        }
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (i == u && j == v) continue;
            if (i != u && j != v) {
                z += a[i][j];
            }
            if (i == u && j != v) {
                x += a[i][j];
            }
            if (i != u && j == v) {
                y += a[i][j];
            }
        }
    }
    // cerr << x << ' ' << y << ' ' << z << '\n';
    cout << (x + y - z / (n-1)) / (n-1);
}
