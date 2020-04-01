#include <bits/stdc++.h>
#define ll long long
const int N=1e5+100;
long long b[N];
long long n,s,l,r,mid,a[N];
using namespace std;
long long cost(ll k)
{
    if (k==0) return 0;
    for (ll i=1;i<=n;i++) b[i]=a[i]+i*k;
    sort(b+1,b+n+1);
    long long res=0;
    for (ll i=1;i<=k;i++) res+=b[i];
    return res;
}
int main()
{
    cin>>n>>s;
    for (ll i=1;i<=n;i++) cin>>a[i];
    l=0; r=n;
    while (l<r)
    {
        mid=(l+r+1)/2;
        if (cost(mid)<=s) l=mid;
        else r=mid-1;
    }
    cout<<l<<" "<<cost(l);
}
