#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e5 + 5;

long long s[N];

int main() {
    // freopen("D.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc, n, m;
    cin >> tc;
    while (tc --) {
        cin >> n >> m;
        int idx = -1;
        long long _min = 1e18, _max = 0, x;
        FOR(i, 1, n) {
            s[i] = 0;
            FOR(j, 1, m) {
                cin >> x;
                s[i] += x * j;
            }
            // cerr << s[i] << '\n';
            _min = min(_min, s[i]);
            _max = max(_max, s[i]);
        }
        // cerr << '\n';
        FOR(i, 1, n) if (s[i] == _max) idx = i;
        cout << idx << ' ' << _max - _min << '\n';
    }
}