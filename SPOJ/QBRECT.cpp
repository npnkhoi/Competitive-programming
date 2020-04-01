#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",a[i]);
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
        for (int i=1;i<=n;i++) if (r[i]-l[i]+1>=k)
            for (int j=l[i],j<=r[i]-k+1,j++) f[j]=a[i];
        for (int i=1;i<=n-k+1;i++) printf("%d ",f[i]);
        printf("\n");
    }
}

