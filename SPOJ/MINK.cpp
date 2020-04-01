#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=17050;
int n,k,l[N],r[N],f[N],tc;
long long a[N];
int main()
{
    //freopen("MINK.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (int i=1;i<=n;i++)
        {
            l[i]=i;
            while (i>1&&(a[i]<=a[l[i]-1])) l[i]=l[l[i]-1];
        }
        for (int i=n;i>=1;i--)
        {
            r[i]=i;
            while (i<n&&a[i]<=a[r[i]+1]) r[i]=r[r[i]+1];
        }
        //for (int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
        for (int i=1;i<=n;i++)
            for (int j=max(l[i],i-k+1);j<=min(r[i],i+k-1);j++) f[j]=a[i];
        for (int i=1;i<=n-k+1;i++) printf("%d ",f[i]);
        printf("\n");
    }
}

