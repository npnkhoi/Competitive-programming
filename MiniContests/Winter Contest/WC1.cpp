#include <bits/stdc++.h>
using namespace std;
#define task "WC1"
int tc, n;
char win, lose;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d %c", &n, &win);
        if (win == 'L') lose = 'B';
        else if (win == 'B') lose = 'K';
        else lose = 'L';
        printf("%c", win);
        for (int i = 1; i < n; i ++) printf("%c", lose);
        printf("\n");
    }
}
