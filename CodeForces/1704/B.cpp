#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 5;

multiset<int> s, t;
int x, f[N], g[N], n, a[N];

bool checkS() {
    int l = *s.begin(), r = *s.rbegin(), mid = (l + r) / 2;
    return max(r - mid, mid - l) <= x;
}

int main() {
    // freopen("B.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc --) {
        s.clear();
        t.clear();
        

        cin >> n >> x;
        f[0] = -1;
        t.insert(-1);
        int j = 0;
        FOR(i, 1, n) {
            cin >> a[i];
            s.insert(a[i]);
            while (!checkS()) {
                s.erase(s.find(a[j + 1]));
                t.erase(t.find(f[j]));
                j ++;
            }
            f[i] = (*t.begin()) + 1;
            t.insert(f[i]);
        }
        cout << f[n] << '\n';
    }
}