#include <bits/stdc++.h>
const long long maxval=10005;
const long long maxN=20005;
using namespace std;
long long n,m;
long long a[maxN],b[maxN];
long long res=0;
void cal(long long a[],long long b[],long long n,long long m)
{
    //for (int i=1;i<=n;i++) cout<<a[i]<<"\t";
    //for (int j=1;j<=m;j++) cout<<b[j]<<"\t";
    //cout<<endl;
    long long bsum[maxval+5]={0};
    long long bcnt[maxval+5]={0};
    for (long long j=1;j<=m;j++) bcnt[b[j]]++;
    //for (int i=1;i<=5;i++) cout<<bcnt[i]<<endl;
    for (long long j=1;j<=maxval;j++) bsum[j]=bsum[j-1]+bcnt[j]*j;
    for (long long j=1;j<=maxval;j++) bcnt[j]+=bcnt[j-1];
    //for (int i=1;i<=5;i++) cout<<bsum[i]<<endl;
    for (long long i=1;i<=n;i++)
    {
        res-=i*((2*bcnt[a[i]]-m)*a[i]+bsum[maxval]-2*bsum[a[i]]);
        //printf("%lld=%lld*((2*%lld-%lld)*%lld+%lld-2*%lld)\n",res,i,bcnt[a[i]],m,a[i],bsum[maxval],bsum[a[i]]);
    }

}
int main()
{
    freopen("TLE.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for (long long i=1;i<=n;i++) { scanf("%lld",&a[i]); }
    for (long long j=1;j<=m;j++) { scanf("%lld",&b[j]); }

    cal(a,b,n,m);
    //cout<<res<<endl;
    res=-res;
    cal(b,a,m,n);
    //cout<<res<<endl;
    printf("%lld",res);
}
