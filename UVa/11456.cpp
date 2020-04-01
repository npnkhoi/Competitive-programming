#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3000;
int TC,n,lis[N],lds[N],res;
ll a[N];
int main()
{
    //freopen("11456.inp","r",stdin);
    //freopen("11456.out","w",stdout);
    scanf("%d",&TC);
    while (TC--)
{
    //cerr<<TC<<endl;
    scanf("%d",&n);
    if (n==0)
    {
        printf("0\n"); continue;
    }
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++)
    {
        lis[i]=1; lds[i]=1;
    }
    for (int i=n-1;i>=1;i--)
        for (int j=i+1;j<=n;j++)
        {
            if (a[j]>a[i]) lis[i]=max(lis[i],lis[j]+1);
            if (a[j]<a[i]) lds[i]=max(lds[i],lds[j]+1);
        }
    res=1;
    //for (int i=1;i<=n;i++) printf("%5d",a[i]); cout<<endl;
    //for (int i=1;i<=n;i++) printf("%5d",lis[i]); cout<<endl;
    //for (int i=1;i<=n;i++) printf("%5d",lds[i]); cout<<endl;
    for (int i=1;i<n;i++) res=max(res,lds[i]+lis[i]-1);
    printf("%d\n",res);
}
}
