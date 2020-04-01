#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("12004.inp","r",stdin);
    //freopen("","w",stdout);
    int tc;
    long long n;
    scanf("%d",&tc);
    for (int i=1;i<=tc;i++)
    {
        scanf("%lld",&n);
        printf("Case %d: ",i);
        if ((n*(n-1))%4==0) printf("%lld\n",n*(n-1)/4);
        else if ((n*(n-1))%2==0) printf("%lld/2\n",n*(n-1)/2);
        else printf("%lld/4\n",n*(n-1));
    }
}
