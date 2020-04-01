#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("10346.inp","r",stdin);
    //freopen("","w",stdout);
    long long n,k;
    while (scanf("%lld%lld",&n,&k)!=EOF)
    {
        long long s=0,cig=n,but=0;
        while (cig)
        {
            s+=cig;
            but+=cig;
            cig=but/k;
            but-=cig*k;
        }
        printf("%lld\n",s);
    }
}
