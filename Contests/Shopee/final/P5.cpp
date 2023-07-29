#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define int long long
using namespace std;

const int N = 1e6 + 5;
pair<int, int> a[N];
multiset<int> s;

signed main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [](const pair<int, int> x, const pair<int, int> y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    int time = 1;
    long long res = 0;
    FOR(i, 1, n) {
        if (time > a[i].first) {
            int t = *s.begin();
            // cerr << "consider remove " << t << '\n';
            if (a[i].second > t) {
                res += a[i].second - t;
                s.erase(s.find(t));
                s.insert(a[i].second);
            }
        } else {
            res += a[i].second;
            s.insert(a[i].second);
            time ++;
        }
    }
    cout << res;
}