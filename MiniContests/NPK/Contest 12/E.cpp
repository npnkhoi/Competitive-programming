#include <bits/stdc++.h>

using namespace std;
const int ooo = -1e9;
int n, k;
const int N = 1e5 + 50;
char a[N];
int p[N], h[N], s[N], f[N][22][4], res;
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        char ch;
        scanf(" %c",&a[i]);
        p[i] = p[i-1] + (a[i] == 'P');
        h[i] = h[i-1] + (a[i] == 'H');
        s[i] = s[i-1] + (a[i] == 'S');
    }
    //====================================
    for (int i = 1; i <= n; i++)
    {
        f[i][0][1] = p[i];
        f[i][0][2] = h[i];
        f[i][0][0] = s[i];
    }
    for (int j = 1; j <= k; j++)
        for (int z = 0; z <= 2; z++)
        f[0][j][z] = ooo;
    //======================================
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++)
    {
        f[i][j][1] = max(f[i-1][j][1], max(f[i-1][j-1][2], f[i-1][j-1][0]))
                    + (a[i] == 'P');
        f[i][j][2] = max(f[i-1][j][2], max(f[i-1][j-1][1], f[i-1][j-1][0]))
                    + (a[i] == 'H');
        f[i][j][0] = max(f[i-1][j][0], max(f[i-1][j-1][1], f[i-1][j-1][2]))
                    + (a[i] == 'S');
    }

    for (int j = 0; j <= k; j++)
        for (int z = 0; z <= 2; z++) res = max(res, f[n][j][z]);
    cout << res;
    return 0;
}
/**/
