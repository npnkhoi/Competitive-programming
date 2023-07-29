#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

map<int, int> s;
int n, x;
long long t;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) {
        cin >> x;
        t += x;
    }
    cout << -t << '\n';
}