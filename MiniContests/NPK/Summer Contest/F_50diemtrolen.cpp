#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,p,q,l,r,mid;
int tc;
bool ok(ll k)
{
    return k*q-b>=k*p-a;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&p,&q);
        ll l=(b+q-1)/q, r=1000000000000000000;
        while (l<r)
        {
            mid=(l+r)/2;
            if (ok(mid)) r=mid;
            else l=mid+1;
        }
        if (ok(l)) printf("%lld\n",l*q-b);
        else printf("-1\n");
    }


}
