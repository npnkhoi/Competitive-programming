#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;
#define task "bricks"
long double g, y, m, n, S, P, delta;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> g >> y;

    S = g/2 + 2;
    P = y + g;
    delta = sqrt(S-2*sqrt(P)) * sqrt(S+2*sqrt(P));
    m = (S - delta) / 2;
    n = (S + delta) / 2;
    //cerr << S << " " << P << " " << delta << " " << m << " " << n << "\n";
    cout << (long long) (m + 0.5) << " " << (long long) (n + 0.5) << "\n";
}
