//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#define ll long long

using namespace std;

int main()
{
    double p,a,b,c,d,n,lo,hi,res;
    freopen("B.inp","r",stdin);
    //freopen("","w",stdout);
    cin>>p>>a>>b>>c>>d>>n;
    hi=p*(sin(a+b)+cos(c+d)+2); res=0;
    for (int i=2;i<=n;i++)
    {
        lo=p*(sin(a*i+b)+cos(c*i+d)+2);
        res=max(res,hi-lo);
        hi=max(hi,p*(sin(a*i+b)+cos(c*i+d)+2));
    }
    printf("%.10f",res);

}
