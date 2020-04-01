//#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;
const int N=1e5+50;
ll tc,n,a[N],l[N],r[N],res,s;
int main()
{
    //freopen("sntemple.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d",&n); s=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        //-------------------
        l[1]=1;
        for (int i=2;i<=n;i++) l[i]=min(l[i-1]+1,a[i]);
        r[n]=1;
        for (int i=n-1;i>=1;i--) r[i]=min(r[i+1]+1,a[i]);
        res=0;
        for (int i=1;i<=n;i++) res=max(res,min(l[i],r[i]));
        printf("%lld\n",s-res*res);
    }
}
