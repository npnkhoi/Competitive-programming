#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int M = 1e5 + 5;

int tc, n, m, a[M];
vector<int> v;

int main() {
    // freopen("C.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> tc;
    while (tc --) {
        v.clear();

        cin >> n >> m;
        FOR(i, 1, m) cin >> a[i];
        sort(a+1, a+m+1);
        // a[0] = 0; a[m+1] = n+1;
        FOR(i, 2, m) {
            if (a[i] - a[i-1] > 1) {
                v.push_back(a[i] - a[i-1] - 1);
            }
        }
        int tmp = a[1] - 1 + n - a[m];
        if (tmp > 0) v.push_back(tmp);
        sort(v.rbegin(), v.rend());
        // cerr << "v: ";
        // for (int i = 0; i < v.size(); ++ i) {
        //     cerr << v[i] << ' '; 
        // }
        // cerr << '\n';

        int res = 0;
        int days = 0;
        for (int i = 0; i < v.size(); ++i) {
            // cerr << i << v[i] << '\n';
            int cur = v[i] - 2 * days;
            if (cur == 1) {
                days ++;
                res += cur;
            } else if (cur > 1) {
                days += 2;
                res += cur - 1;
            } else {
                break;
            }
            // res += max(1, v[i] - (2 * i + 1));
        }
        cout << n - res << '\n';
    }
}