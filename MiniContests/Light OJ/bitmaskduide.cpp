#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,c[20][20],f[1<<18],TC;
int main()
{
    //freopen("duide.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) scanf("%d",&c[i][j]);
        for (int j=0;j<n;j++) f[1<<j]=c[0][j];
        //================
        for (int mask=1;mask<(1<<n);mask++)
            if (__builtin_popcount(mask)>0)
                for (int x=0;x<n;x++) if ((mask&(1<<x))>0)
                f[mask]=max(f[mask],f[mask^(1<<x)]+c[__builtin_popcount(mask)-1][x]);
        printf("Case %d: %d\n",tc,f[(1<<n)-1]);
    }
}
