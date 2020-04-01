using namespace std;
#include <stdio.h>
int n, a[100010], cnt;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n-1; i > 0; i--) if (a[i-1] > a[i]) break;
    else cnt ++;
    printf("%d", n - cnt - 1);
}
