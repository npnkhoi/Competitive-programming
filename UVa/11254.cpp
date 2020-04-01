#include <bits/stdc++.h>
using namespace std;
long long n;
bool ok(long long x)
{
    return ((x*x+x<=2*n)&&((2*n-x*x-x)%(2*x)==0));
}
int main()
{
    //freopen("11254.inp","r",stdin);
    //freopen("11254.out","w",stdout);
while (1)
{
    scanf("%lld",&n);
    if (n<0) break;
    long long res=1;
    for (long long x=1;x<=sqrt(2*n);x++)
    {
        if (ok(x)) res=max(res,x);
        if ((2*n)%x==0) if (ok((2*n)/x)) res=max(res,(2*n)/x);
    }
    long long a=(2*n-res*res-res)/res/2;
    printf("%lld = %lld + ... + %lld\n",n,a+1,a+res);
}
}
