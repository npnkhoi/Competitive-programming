using namespace std;
#include <stdio.h>
#include <iostream>
const int N = 210;
const int oo = 1e9;
int t, k, m, n;
int sa[N], sb[N], la[N], lb[N], f[N][N][2];
int main()
{
    freopen("bridge.inp","r",stdin);
    //freopen("bridge.out","w",stdout);
    scanf("%d %d", &t, &k);
    while (t--)
    {
        char ch;
        scanf(" %c",&ch);
        if (ch == 'A') m++, scanf("%d %d",&sa[m], &la[m]);
        else n++, scanf("%d %d", &sb[n], &lb[n]);
    }
    /*for (int i = 1; i<= m ;i++) printf(" %d %d\n",sa[i], la[i]);
    cout << endl;
    for (int i = 1; i<= n ;i++) printf(" %d %d\n",sb[i], lb[i]);
    cout << endl;*/
    f[0][0][0] = f[0][0][1] = -k;
    for (int i = 1; i <= m; i++)
    {
        f[i][0][0] = max(f[i-1][0][0] + k, sa[i]);
        f[i][0][1] = oo;
    }
    for (int i = 1; i <= n; i++)
    {
        f[0][i][1] = max(f[0][i-1][1] + k, sb[i]);
        f[0][i][0] = oo;
    }
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
        //printf("%d vs %d\n",max(f[i-1][j][0] + k, sa[i]), max(f[i-1][j][1] + lb[j], sa[i]));
        f[i][j][0] = min(   max(f[i-1][j][0] + k, sa[i]),
                            max(f[i-1][j][1] + lb[j], sa[i]));
        printf("f[%d][%d][0]=%d\n",i,j,f[i][j][0]);


        //printf("%d vs %d\n",max(f[i][j-1][1] + k, sb[j]), max(f[i][j-1][0] + la[i], sb[j]));
        f[i][j][1] = min(   max(f[i][j-1][1] + k , sb[j]),
                            max(f[i][j-1][0] + la[i], sb[j]));
        printf("f[%d][%d][1]=%d\n",i,j,f[i][j][1]);
    }
    cout << min (   f[m][n][0] + la[m],
                    f[m][n][1] + lb[n] );
}
