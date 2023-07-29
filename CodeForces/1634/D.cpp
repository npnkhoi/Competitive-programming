#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int query(int i, int j, int k) {
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc, n;
    cin >> tc;
    while (tc --) {
        cin >> n;
        int x = 1, y = 2;
        pair<int, int> lst[4];

        for (int i = 4; i <= n; i += 2) {
            lst[0] = {query(y, i-1, i), x};
            lst[1] = {query(x, i-1, i), y};
            lst[2] = {query(x, y, i), i-1};
            lst[3] = {query(x, y, i-1), i};
            
            sort(lst, lst+4);
            x = lst[0].second; y = lst[1].second;
        }

        if (n%2) {
            int j = lst[2].second;
            lst[0] = {query(y, j, n), x};
            lst[1] = {query(x, j, n), y};
            lst[2] = {query(x, y, n), j};
            lst[3] = {query(x, y, j), n};
        }
        sort(lst, lst+4);
        
        cout << "! " << lst[0].second << ' ' << lst[1].second << endl;
    }
}