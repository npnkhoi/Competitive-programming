using namespace std;
#include <stdio.h>
int f[15];
int main() {
    int tc = 0, n;
    f[0] = 1;
    for (int i = 1; i <= 10; i++) f[i] = f[i-1] * (2*i) * (2*i - 1) / i / (i+1);
    while (scanf("%d", &n) != EOF) {
        if (tc++) printf("\n");
        printf("%d\n", f[n]);
    }
}
