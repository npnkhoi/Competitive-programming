#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int oo=1e9;
int tc,n,total,s,f[110][1100000],a[110];
int main()
{
    //freopen("11517.inp","r",stdin);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d%d",&s,&n);
        total=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            total+=a[i];
        }
        for (int i=0;i<=n;i++) f[i][0]=0;
        for (int j=1;j<=total;j++) f[0][j]=oo;
        for (int i=1;i<=n;i++)
            for (int j=0;j<total;j++)
        if (a[i]<=j) f[i][j]=min(f[i-1][j],1+f[i-1][j-a[i]]);
            else f[i][j]=f[i-1][j];
        int j=s-1;
        for (int j=s;j<=total;j++)
        if (f[n][j]!=oo)
        {
            printf("%d %d\n",j,f[n][j]);
            break;
        }
    }
}
