#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int n, q;
set<int> s;

bool check(int a, int b) {
    if (a > b) swap(a, b);
    if (s.find(a) != s.end() || s.find(b) != s.end()) return false;
    
    set<int>::iterator t = s.upper_bound(a);
    if (t == s.end() || *t > b) return true;

    t = s.upper_bound(0);
    if (*t < a) return false;
    t = s.upper_bound(b);
    if  (*t > b) return false;
    return true;
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> n >> q;
    while (q--) {
        char ty;
        int a, b;
        cin >> ty;
        if (ty == '-') {
            cin >> a;
            s.insert(a);
        } else if (ty == '+') {
            cin >> a;
            s.erase(a);
        } else {
            cin >> a >> b;
            cout << (check(a, b) ? "possible" : "impossible") << '\n';
        }
    }
}