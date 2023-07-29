
#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;
#define int long long

int N, a, kx, ans;

signed main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    N = 2000000000001;
    cout << "? " << N << endl;
    cin >> a;
    kx = N - a;
    cout << "? " << (N + kx - 1) / kx * kx + kx - 1 << endl;
    cin >> ans;
    cout << "! " << ans + 1 << endl;
}