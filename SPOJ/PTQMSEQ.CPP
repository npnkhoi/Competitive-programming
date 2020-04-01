#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    //read input ---------------------
    //freopen("PTQMSEQ.inp","r",stdin);
    int maxn=1100000;
    int n,i;
    scanf("%d",&n);
    int a[maxn];
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    //xuli 1--------------------------
    int cnt=0;
    long long res1=a[1],sum=0;
    for (i=1;i<=n;i++)
    {
        sum+=a[i];
        cnt++;
        if (sum<=0)
        {
            sum=cnt=0;
            continue;
        }
        if (cnt<n) res1=max(res1,sum);
            else res1=max(res1,sum-a[1]);
    }
    // xu li 2 -------------------------
    long long res2=a[1];
    sum=0;
    for (i=1;i<=n;i++)
    {
        sum+=a[i];
        cnt++;
        if (sum>=0)
        {
            sum=cnt=0;
            continue;
        }
        if (cnt<n) res2=min(res2,sum);
            else res2=min(res2,sum-a[1]);
    }
    //printf output -----------------
    sum=0;
    for (i=1;i<=n;i++) sum+=a[i];
    if (n>1) {printf("%lld",max(res1,sum-res2));}
}
