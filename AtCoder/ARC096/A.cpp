#include <bits/stdc++.h>
using namespace std;

long long a, b, c, x, y, tmp, res;
int main() {
    cin >> a >> b >> c >> x >> y;
    if (a + b < c + c) res = (a + b) * min(x, y);
    else res = 2 * c * min(x, y);
    tmp = min(x, y);
    x -= tmp; y -= tmp;
    if (x > 0) {
        if (a < 2*c) res += x * a;
        else res += x * 2 * c;
    } else if (y > 0) {
        if (b < 2*c) res += y * b;
        else res += y * 2 * c;
    }
    cout << res;
}
