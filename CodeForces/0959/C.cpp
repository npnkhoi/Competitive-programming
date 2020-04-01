#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if (n <= 5) printf("-1\n");
    else {
        printf("1 2\n");
        printf("2 3\n");
        printf("2 4\n");
        for (int i = 5; i <= n; i++) printf("4 %d\n", i);
    }
    for (int i = 1; i < n; i++) printf("%d %d\n", i, i+1);
}
