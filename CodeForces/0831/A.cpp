using namespace std;
#include <stdio.h>
int n, a[110];
int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int i;
    for (i = 1; i < n; i++) if (a[i] >= a[i+1]) break;
    for (; i < n; i++) if (a[i] != a[i+1]) break;
    for (; i < n; i++) if (a[i] <= a[i+1]) {
        printf("NO"); return 0;
    }
    printf("YES");
}
