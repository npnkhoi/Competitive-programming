#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int tc; cin >> tc;

    // string s = "Abc";
    // cout << s == "Abc" << endl;
    while(tc--) {
        int n; cin >> n;
        string s; cin >> s;
        sort(s.begin(), s.end());
        if(s == "Timru") cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}