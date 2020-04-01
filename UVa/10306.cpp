#include <bits/stdc++.h>
using namespace std;
const int oo=1e9;
const int N=50;
const int S=350;
int n,s,a[N],b[N],f[N][S][S],res,tc;
int main()
{
    //freopen("10306.inp","r",stdin);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d%d",&n,&s);
        //printf("%d %d\n",n,s);
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);

        for (int i=0;i<=s;i++)
            for (int j=0;j<=s;j++)
            f[0][i][j]=oo;
        f[0][0][0]=0;
        //----------------------------
        for (int t=1;t<=n;t++)
        for (int i=0;i<=s;i++)
            for (int j=0;j<=s;j++)
        {
            f[t][i][j]=f[t-1][i][j];
            //printf("f[%d,%d,%d]=%d\n",t,i,j,f[t][i][j]);
            //printf("%d<%d, %d<%d\n",a[t],i,b[t],j);
            if (a[t]<=i&&b[t]<=j)
                f[t][i][j]=min(f[t][i][j],1+min(f[t-1][i-a[t]][j-b[t]],f[t][i-a[t]][j-b[t]]));
            //printf("f[%d,%d,%d]=%d\n",t,i,j,f[t][i][j]);
        }
        res=oo;
        for (int i=0;i<=s;i++)
            for (int j=0;j<=s;j++)
            if ((i*i+j*j)==s*s)
            {
                res=min(res,f[n][i][j]);
                //printf("%d %d ->> %d\n",i,j,res);
            }
        if (res==oo) printf("not possible\n");
        else  printf("%d\n",res);
    }
}
