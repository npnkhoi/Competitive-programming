#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

bool check(int n, int k) {
    if (k == 1) return true;
    return n % 2 == 0;
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc, n, k;
    cin >> tc;
    while (tc --) {
        cin >> n >> k;
        if (!check(n, k)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        FOR(i, 1, n) {
            FOR(j, 0, k-1) {
                cout << j * n + i << ' ';
            }
            cout << '\n';
        }
    }
}