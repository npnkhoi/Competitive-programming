using namespace std;
#include <stdio.h>
#include <iostream>

const int N = 1e5 + 50;
int a[N];

int main() {
    int n, k, b;
    scanf("%d %d %d", &n, &k, &b);
    int x;
    while (b--) scanf("%d", &x), a[x] = 1;

    int res, tmp = 0;

    for (int i = 1; i <= k; i++) tmp += a[i];

    res = tmp;

    for (int i = k+1; i <= n; i++) tmp += a[i] - a[i-k], res = min(res, tmp);

    cout << res;
}
