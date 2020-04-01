using namespace std;
#include <stdio.h>
#include <algorithm>
const int N = 1e5 + 50;
int n, a[N], b[N], res = 0;
int main () {
    freopen("unfair.inp", "r", stdin);
    freopen("unfair.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int j = n + 1;
    for (int i = n; i >= 1; i--) {
        do j --; while (j >= 1 && a[j] >= b[i]);
        //printf("%d\n", j);
        res += (j >= 1);
    }
    printf("%d", res);
}
