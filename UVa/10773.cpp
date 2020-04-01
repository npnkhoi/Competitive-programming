#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TC;
    double d,u,v;
    cin>>TC;
    for (int i=1;i<=TC;i++)
    {
        scanf("%lf%lf%lf",&d,&v,&u);
        printf("Case %d: ",i);
        if ((u==0)||(v==0)||(u<=v)) printf("can't determine\n");
        else printf("%.3lf\n",d*(1/sqrt(u*u-v*v)-1/u));
    }

}
