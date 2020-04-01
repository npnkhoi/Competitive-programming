#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    //freopen("810B.inp","r",stdin);
    //freopen("","w",stdout);
    const int N=1e5+50;
    int k[N],l[N],f,n;
    ll a[N],res;
    scanf("%d%d",&n,&f);
    for (int i=1;i<=n;i++) scanf("%d%d",&k[i],&l[i]);
    res=0;
    for (int i=1;i<=n;i++) res+=min(k[i],l[i]);
    //cout<<res;
    for (int i=1;i<=n;i++) a[i]=min(k[i]+k[i],l[i])-min(k[i],l[i]);
    //for (int i=1;i<=n;i++) cout<<a[i]<<endl;
    sort(a+1,a+n+1);
    for (int i=1;i<=f;i++) res+=a[n-i+1];
    cout<<res;
}

