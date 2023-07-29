#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 20;

int n, a[N];

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        cin >> n;
        int _min = n;
        FOR(i, 1, n) {
            cin >> a[i];
            _min = min(_min, a[i]);
        }
        cout << (a[1] == _min ? "Yes" : "No") << '\n';
    }
}