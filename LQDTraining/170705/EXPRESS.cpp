using namespace std;
#include <stdio.h>
#include <iostream>

int n;
long long a[10010];
long long f[10010];
long long s = 0;

int main() {
    freopen("express.inp", "r", stdin);
    freopen("express.out", "w", stdout);
    scanf("%d", &n);
    for (int i  = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s += a[i];
    }
    long long tmp = -123456789, res = -123456789;
    for (int i = 1; i < n; i ++) {
        f[i] = a[i]*a[i+1] - a[i] - a[i+1];
        if (i >= 3) {
            tmp = max(tmp, f[i-2]);
            res = max(res, f[i] + tmp);
        }
    }
    for (int i = 1; i <= n-2; i++) res = max(res, a[i]*a[i+1]*a[i+2] - a[i] - a[i+1] - a[i+2]);
    cout << s + res;

}
