using namespace std;
#include <stdio.h>
#include <math.h>
const int N = 1e5 + 50;
int n, q;
int a[N], f[N][320];
int main()
{
    scanf("%d", &n );
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int p = n; p >= 1; p--)
        for (int k = 1; k <= sqrt(n); k++)
    if (p + a[p] + k > n) f[p][k] = 1;
        else f[p][k] = 1 + f[p + a[p] + k][k];
    scanf("%d ", &q);
    while (q--)
    {
        int p, k;
        scanf("%d %d", &p, &k);
        if (k <= sqrt(n)) printf("%d\n", f[p][k]);
        else
        {
            int cnt = 0;
            for (; p <= n; p += a[p] + k) cnt ++;
            printf("%d\n",cnt);
        }
    }
}
