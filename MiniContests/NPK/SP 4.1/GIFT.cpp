using namespace std;
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
const int N = 1e6 + 10;
int m,n,b[N],f[N];
int x,last,res;
int vt(int x)
{
    int l,r,mid;
    l=x;
    r=last/x*x + x;
    while (l<r)
    {
        mid = (l+r) / 2;
        if (!f[mid]) r=mid; else l=mid+x;
    }
    //printf("vt %d = %d\n",x,l);
    return l;
}
int main()
{
    freopen("GIFTS.inp","r",stdin);;
    freopen("GIFTS.out","w",stdout);
    last = 0;
    scanf("%d", &m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        last=max(last,b[i]);
    }
    //------------------------------------
    scanf("%d",&n); memset(f, 0, sizeof(f));
    while (n--)
    {
        scanf("%d",&x);
        long long k = 1LL * vt(x);
        for (int i=k;i<=min(k+1LL*x*x-x,1LL*last);i+=x)
        {
            f[i] = 1; //printf("mark %d\n",i);
        }
    }
    res = 0;
    while (m--) res+=f[b[m+1]];
    printf("%d",res);
}
