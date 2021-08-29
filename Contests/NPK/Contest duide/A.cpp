
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=1e5+50;
int n,q,u,v;
int a[N];
int l,r, mid, ll, rr;
int main()
{
    //freopen("A.inp","r",stdin);
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    while (q--)
    {
        scanf("%d%d",&u,&v);
        l=1; r=n;
        while (l<r)
        {
            mid = (l+r) / 2;
            if (a[mid]>=u) r=mid; else l=mid+1;
        }
        if (a[l]<u) l++; ll=l;
        l=1; r=n;
        while (l<r)
        {
            mid= (l+r+1)/2;
            if (a[mid]<=v) l=mid; else r=mid-1;
        }
        if (a[r]>v) r--; rr=r;
        //printf("%d %d\n",ll,rr);
        printf("%d\n",rr-ll+1);
    }
}
