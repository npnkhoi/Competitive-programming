#include <bits/stdc++.h>
using namespace std;
long long a, x, y, z, d, h;
void sol() {
    cin >> y >> x; x++; y++;
    z = 0;
    d = 1LL << a; h = 1LL;
    x = d + 1 - x;
    //printf("%lld %lld %lld\n", x, y, z);
    while (d > 1) {
        //cout << d << " " << h << endl;
        if (x <= d/2 && y <= d/2)
            z += 3*h;
        else if (x > d/2 && y <= d/2)
            x = d+1-x, z = h-z-1;
        else if (x > d/2 && y > d/2)
            x = d+1-x, y = d+1-y, z += h;
        else y = d+1-y, z = 3*h-1-z;
        //printf("%lld %lld %lld\n", x, y, z);
        d /= 2; h *= 4;
    }
    cout << z + 1 << " ";
}
int main() {
    cin >> a;
    sol(); sol();
}
