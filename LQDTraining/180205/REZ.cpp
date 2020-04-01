#include <cstdio>
using namespace std;

int main() {
    freopen("REZ.inp", "r", stdin);
    freopen("REZ.out", "w", stdout);
    int n, k, cnt;
    scanf("%d", &k);

    cnt = 1, n = 0;
    while (cnt < k) cnt += (++n);
    printf("%d", n);
}
