#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 5e4 + 5;
int tc, n, num, a[N], res;
int check(int x) {
    int tmp = -1;
    FOR(i, 1, n) if (a[i] % x != 0)
        if (tmp == -1) tmp = a[i];
        else tmp = __gcd(tmp, a[i]);
    //printf("check %d :%d\n", x, tmp);
    if (tmp == -1) return x;
    else return tmp;
}
int main() {
    freopen("SOCOLA.inp", "r", stdin);
    freopen("SOCOLA.out", "w", stdout);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        FOR(i, 1, n) scanf("%d", &a[i]);
        num = a[(n+1)/2];
        //printf("num: %d\n", num);
        res = 1;
        FOR(i, 1, sqrt(num) + 1) if (num % i == 0) {
            res = max(res, min(i, check(i)));
            res = max(res, min(num/i, check(num/i)));
        }
        printf("%d\n", res);
    }
}

