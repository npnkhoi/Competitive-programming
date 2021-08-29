#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    double s,a1,a2;
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%lf%lf%lf",&s,&a1,&a2);
    double t=sqrt(2*s/(a1+a2));
    printf("%.10f %.10f",a1*t,a2*t);
}
