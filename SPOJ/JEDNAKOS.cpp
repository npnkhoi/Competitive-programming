using namespace std;
#include <stdio.h>
#include <cstring>
#include <algorithm>
const int N = 1010;
const int K = 5010;
const int oo = 1e9 + 7;

char str[N];
int f[N][7][K];
int pre[N];
int lt[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    scanf("%s", str + 1);
    int n = strlen(str+1);
    int tmp = 1, k = 0;
    while (str[n] != '=') {
        k += tmp*(str[n] - '0');
        tmp *= 10;
        n--;
    } n--;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) pre[i] = (str[i] == '0') ? pre[i-1] : i;

    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 6; j++)
    for (int l = 0; l <= k; l++) {
        if (j == 6) f[i][j][l] = oo;
        else if (i == 0) f[i][j][l] = (l == 0) ? 0 : oo;
        else {
            int tmp = l - (str[i] - '0')*lt[j];
            if (tmp < 0) f[i][j][l] = oo;
            else {
                f[i][j][l] = min( f[i-1][j+1][tmp], 1 + f[i-1][0][tmp]);
                if (str[i] == '0') f[i][j][l] = min(f[i][j][l], 1 + f[pre[i]][0][l]);
            }
        }
        //printf("%d %d %d: %d\n", i, j, l, f[i][j][l]);
    }
    printf("%d", f[n][0][k]);

}
