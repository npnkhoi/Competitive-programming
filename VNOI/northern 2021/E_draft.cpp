#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

bool is_prime(int x) {
    if (x <= 1) return false;
    FOR(i, 2, sqrt(x)) {
        if (x % i == 0) return false;
    }
    return true;
}

int sumDigits(long long x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

bool special(long long x) {
    return is_prime(sumDigits(x));
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n = 200;
    FOR(y, 1, n/2) {
        int x = n - 2 * y;
        cerr << x << ' ' << y << " - " << sumDigits(x) << ' ' << sumDigits(y);
        if (is_prime(sumDigits(x)) && is_prime(sumDigits(y))) cerr << " YES!";
        cerr << '\n';
    }
}