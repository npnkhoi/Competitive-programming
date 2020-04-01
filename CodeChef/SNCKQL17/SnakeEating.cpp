#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxN=100000+5;
long long k,L[maxN],sum[maxN],T,n,q;
long long s(long long i, long long j)
{
    return sum[j]-sum[i-1];
}
void sol()//logN
{
    ll l,r,mid,flag;
    l=0; r=n;
    while (l<r)
    {
        mid=(l+r+1)/2;
        if (L[mid]>=k) l=mid;
        else r=mid-1;
    }
    flag=l;
    l=flag; r=n;
    while (l<r)
    {
        mid=(l+r+1)/2;
        if ((k+1)*(mid-flag)-s(flag+1,mid)<=n-flag) l=mid;
        else r=mid-1;
    }
    printf("%lld\n",l);
}
bool right_ord(long long a, long long b)
{
    return a>=b;
}
int main()
{
    freopen("SnakeEating.inp","r",stdin);
    //freopen("","w",stdout);
    L[0]=1e9+100;
    scanf("%lld",&T);
    while (T--)
    {
        scanf("%lld%lld",&n,&q);
        for (int i=1;i<=n;i++) scanf("%lld",&L[i]);//N
        sort(L+1,L+n+1,right_ord);//NlogN
        //===============================
        sum[0]=0;
        for (int i=1;i<=n;i++) sum[i]=sum[i-1]+L[i];//N
        //================================
        for (int i=1;i<=q;i++) //q*logN
        {
            scanf("%lld",&k);
            sol();
        }
    }
}
