#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6 + 10;
const ll oo = 1e18;
ll n, k, p, q, m, l[N], r_i, res;
ll val(int i) {return p*i%m+q + i*k;}
int main() {
    cin >> n >> k >> p >> q >> m;
    for (int i = 1; i <= n; i++) l[i] = max(l[i-1], val(i));
    res = oo; r_i = 0;
    for (int i = n; i >= 1; i--) {
        r_i = max(r_i, val(i));
        res = min(res, max(r_i - k*(i-1), l[i-1] + k*(n-i+1)));

    }
    cout << res;
}
