#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,f[1010][1010],c[1010],w[1010];
int main()
{
    //freopen("K.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d%d",&c[i],&w[i]);

    for (int i=0;i<=n;i++) f[i][0]=0;
    for (int j=0;j<=m;j++) f[0][j]=0;
    for (int j=1;j<=m;j++) if (j>=w[1]) f[1][j]=c[1]; else f[1][j]=0;

    for (int i=2;i<=n;i++)
    for (int j=1;j<=m;j++)
        if (j<w[i]) f[i][j]=f[i-1][j];
        else
        f[i][j]=max(f[i-1][j],c[i]+f[i-2][j-w[i]]);
    printf("%d",f[n][m]);
}
