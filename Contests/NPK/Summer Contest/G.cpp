#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    double n,h;
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%lf%lf",&n,&h);
    for (int i=1;i<(int)n;i++)
    {
        printf("%.10f ",h*sqrt(i/n));
    }
}
