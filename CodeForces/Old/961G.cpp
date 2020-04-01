#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
long long Pow(int a, int x) {
    if (x == 0) return 1;
    else {
        long long res = Pow(a, x / 2);
        res = res * res % md;
        if (x % 2) res = res * a % md;
        return res;
    }
}
long long choose(int n, int k) {
    long long res = 1;
    for (int i = k + 1; i <= n; i++) res = res * i % md;
    for (int i = 1; i <= n-k; i++) res = res * Pow(i, md - 2) % md;
    return res;
}
long long stirl(int n, int k) {
    long long res = 0;
    long long tmp;
    if (k % 2) tmp = -1; else tmp  = 1;
    for (int j = 0; j <= k; j++) {
        res = (res + tmp * Pow(j, n)) % md;
        //cerr << "choose " << k << " " << j << " = " << choose(k, j) << "\n";
        tmp = - tmp * (k - (j+1) + 1) % md * Pow((j+1), md - 2) % md;
    }
    for (int i = 2; i <= k; i++) res = res * Pow(i, md - 2) % md;
    if (res < 0) res += md;
    return res;
}
int main() {
    int n, k;
    long long s = 0;
    scanf("%d%d", &n, &k);
    //cerr << stirl(n-1, k) << " " << stirl(n, k) << "\n";
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        s = (s + val) % md;
    }
    s = s * (stirl(n-1, k) * (n-1) % md + stirl(n, k)) % md;
    printf("%lld", s);
}
