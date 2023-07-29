#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, md = 1e9 + 7;

int k, f[N], s[N];

int main() {
    cin >> k;
    f[1] = s[1] = 1;
    for (int i = 2; i <= k; ++ i) {
        f[i] = (s[i-1] - s[(i + 1) / 2 - 1] + md) % md;
        s[i] = (s[i-1] + f[i]) % md;
    }
    cout << f[k];
}
