#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7;
int TC,n;
ll h[N],w[N],lis[N],lds[N],a,b,maxi,maxd;
int main()
{
    //freopen("11790.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        scanf("%d",&n);
        a=0; b=0;
        for (int i=1;i<=n;i++) scanf("%lld",&h[i]);
        for (int i=1;i<=n;i++) scanf("%lld",&w[i]);
        //===========================================
        for (int i=1;i<=n;i++)
        {
            maxi=0; maxd=0;
            for (int j=i-1;j>=1;j--)
            {
                if (h[j]<h[i]) maxi=max(maxi,lis[j]);
                if (h[j]>h[i]) maxd=max(maxd,lds[j]);
            }
            lis[i]=w[i]+maxi; lds[i]=w[i]+maxd;
            a=max(a,lis[i]); b=max(b,lds[i]);
        }
        if (a>=b)
            printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",tc,a,b);
        else
            printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",tc,b,a);
    }

}
