#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        int n;
        string s;

        cin >> n >> s;

        int res = 0;
        FOR(i, 1, n-1) {
            if (s[i] == '1') continue;

            if (s[i-1] == '0') res += 2;
            else if (i >= 2 && s[i-2] == '0') res ++;
        }
        cout << res << '\n';
    }
}