#include <bits/stdc++.h>
using namespace std;

int n, x, y, lim;

int g(int x) {
    if (x % 2 == 1) return 0;
    else return 1 + g(x / 2);
}

int main() {
    // freopen("test.inp", "r", stdin);
    cin >> n >> x >> y;
    cout << n - 1 - g(x);
}
