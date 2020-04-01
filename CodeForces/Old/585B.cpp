using namespace std;
#include <stdio.h>
#include <algorithm>

int tc, n, k;
char a[110][4];

bool reachable(char ch) {
    return ch == '.' || ch == 's';
}
bool ok(int j, int i, int k) {

        a[j-3][k] == 's' && reachable(a[j-2][k]) && reachable(a[j-2][i]) &&
        return ( abs(i-k) <= 1 &&
        reachable(a[j-2][i]) && reachable(a[j-1][i]) && reachable(a[j][i]) );
}
int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &k);

        for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++) scanf(" %c", &a[j][i]);

        for (int i = 0; i < 3; i++)
        for (int j = n; j <= n+2; j++) a[j][i] = '.';

        n += 3;

        for (int j = 3; j < n; j++)
            for (int i = 0; i < 3; i++)
            for (int k = 0; k < 3; k++)
            if (ok(j, i, k)) a[j][i] = 's';

        bool res = 0;

        for (int i = 0; i < 3; i++)
        for (int j = n-3; j <= n-1; j++)
        res |= (a[j][i] == 's');
        if (res) printf("YES\n");
        else printf("NO\n");
        /*for (int i = 0; i <= 2; i++)    {
            for (int j = 0; j < n; j++) printf("%c", a[j][i]);
            printf("\n");
        }*/
    }
}
