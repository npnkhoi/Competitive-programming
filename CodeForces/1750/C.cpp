#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 5;

int n;
string a, b;
vector<pair<int, int>> ans;

int main() {
    // freopen("C.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc; cin >> tc;
    while (tc --) {
        ans.clear();

        cin >> n >> a >> b;
        int sum = (a[0] - '0') ^ (b[0] - '0');
        bool flag = false;
        FOR(i, 1, (n-1)) {
            int tmp = (a[i] - '0') ^ (b[i] - '0');
            if (tmp != sum) flag = true;
        }
        if (flag) {
            cout << "NO\n";
            continue;
        }

        int lastZero = -1, cnt = 0;
        FOR(i, 0, (n-1)) {
            if (a[i] == '1') {
                if (i == n-1 || a[i+1] == '0') {
                    ans.push_back({lastZero + 1, i});
                    // cout << lastZero + 1 << ' ' << i << '\n';
                    sum ^= 1;
                }
            } else {
                lastZero = i;
            }
        }
        if (sum == 1) {
            ans.push_back({0, 0});
            ans.push_back({1, n-1});
            ans.push_back({0, n-1});
            // cout << "1 1\n";
            // cout << 2 << ' ' << n << '\n';
            // cout << 1 << ' ' << n << '\n';
        }
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x.first + 1 << ' ' << x.second + 1 << '\n';
        }
    }
}