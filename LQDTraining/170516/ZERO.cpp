#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("ZERO.INP","r",stdin);
    //freopen("ZERO.OUT","w",stdout);
    long long n,x,s,i;
    scanf("%lld",&n);
    x=1; s=0; i=0;
    while (5*x<=n)
    {
        i++;
        x=5*x;
        long long them= (n/x);
        s+=them;
        //cout<<them<<" "<<s<<endl;
    }
    printf("%lld",s);
}

