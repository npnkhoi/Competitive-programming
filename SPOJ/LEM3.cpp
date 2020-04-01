#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int oo=1000000;
int c[20][20],n;
ll res,dp[20][1000000];
int main()
{
    //freopen("LEM3.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int mask=0;mask<(1<<n);mask++) dp[i][mask]=oo;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) scanf("%d",&c[i][j]);

    for (int i=0;i<n;i++) dp[i][1<<i]=0;

    for (int mask=1;mask<(1<<n);mask++)
        for (int i=0;i<n;i++) if ((mask&(1<<i))>0)
    {
        for (int x=0;x<n;x++) if (((mask&(1<<x))>0)&&(x!=i))
            dp[i][mask]=min(dp[i][mask],c[x][i]+dp[x][mask^(1<<i)]);
    }
    res=oo;
    for (int i=0;i<n;i++) res=min(res,dp[i][(1<<n)-1]);
    printf("%lld",res);
}
