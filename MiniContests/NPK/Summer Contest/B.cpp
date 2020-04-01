#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,r,res,a[1010][1010],sum[1010][1010];
int s(int x, int y, int u, int v)
{
    return sum[u][v]-sum[x-1][v]-sum[u][y-1]+sum[x-1][y-1];
}
int damage(int x,int y)
{
    if (a[x][y]==0) return 0;
    return s(max(x-r,1),max(y-r,1),min(x+r,n),min(y+r,m));
}
int main()
{
    //freopen("B.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d",&n,&m,&r);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
        }
    res =0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        res=max(res,damage(i,j));
    printf("%d",res);

}
