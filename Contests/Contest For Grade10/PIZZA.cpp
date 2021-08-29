#include <bits/stdc++.h>
using namespace std;
long long a, b, c, x, y, res;
int main() {
    cin >> a >> b >> c >> x >> y;

    if (a + b < c + c) res = (a + b) * min(x, y);
    else res = 2 * c * min(x, y);
    
    if (x > y) {
        if (a < 2 * c) res += (x - y) * a;
        else res += (x - y) * 2 * c;
    } else if (y > x) {
        if (b < 2 * c) res += (y - x) * b;
        else res += (y - x) * 2 * c;
    }

    cout << res;
}
