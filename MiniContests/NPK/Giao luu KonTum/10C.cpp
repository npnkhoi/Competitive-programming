#include <bits/stdc++.h>
using namespace std;
long long d,k,a,b,t,res;
int main()
{
    scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
    if (d<=k) res=d*a;
    else res=k*a+(d/k-1)*min(t+k*a,k*b)+min((d%k)*a+t,(d%k)*b);
    printf("%lld",res);
}
