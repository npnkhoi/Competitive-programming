#include <bits/stdc++.h>
using namespace std;
int t;
long long n,m,k;
int main()
{
    freopen("VINAPHONE.INP","r",stdin);
    freopen("VINAPHONE.OUT","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        m+=n; k+= m;
        if ((n>145)||(m>180)||(k>900)) printf("NO\n");
        else printf("YES\n");
    }

}

