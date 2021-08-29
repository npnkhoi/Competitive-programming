#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bitset<N> sign;
int n, x, y, res, num;
bool inU(int num) {
    num -= x;
    return (num >= 0 && num % y == 0);
}
int main() {
    freopen("BAI1_1617.inp", "r", stdin);
    freopen("BAI1_1617.out", "w", stdout);

    sign[0] = sign[1] = 1;
    for (int i = 2; i <= 1e6 + 2; i++) if (sign[i] == 0)
    for (long long j = 1LL*i*i; j <= 1e6 + 2; j += 1LL * i) sign[j] = 1;

    scanf("%d %d %d", &n, &x, &y);
    while (n--) {
        scanf("%d", &num);
        res += (!sign[num]) && (inU(num));
    }
    printf("%d", res);
}
