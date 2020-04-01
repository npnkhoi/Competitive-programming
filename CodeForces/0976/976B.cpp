#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int main() {
    cin >> n >> m >> k;
    if (k < n) cout << k + 1 << ' ' << 1;
    else {
        long long x = (k - n) / (m - 1);
        long long y = (k - n) % (m - 1);
        //cerr << x << " " << y << "\n";
        cout << n - x << ' ';
        if (x % 2 == 0) cout << 2 + y;
        else cout << m - y;
    }
}
