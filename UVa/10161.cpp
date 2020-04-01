#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("10161.inp","r",stdin);
    //freopen("","w",stdout);
    long long n,s,x,y;
    while (1)
    {
        scanf("%lld",&n);
        if (!n) break;
        s=sqrt(n);
        if (s*s!=n) s++;
        if (s%2)
        {
            y=1; x=s;
            if (n>s*s-s+1) y+=s*s-n;
            else {y=s; x-=s*s-s+1-n;}
        }
        else
        {
            x=1; y=s;
            if (n>s*s-s+1) x+=s*s-n;
            else {x=s; y-=s*s-s+1-n;}
        }
        printf("%lld %lld\n",y,x);
    }
}
