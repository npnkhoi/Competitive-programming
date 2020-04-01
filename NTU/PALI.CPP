#include <iostream>
#include <stdio.h>
//#include <bits/stdc++.h>
using namespace std;
int palin(int x)
{
    int y=x,z=0;
    while (y>0)
    {
        z=10*z+y%10;
        y=y/10;
    }
    return z==x;
}
int main()
{
    //freopen("pali.inp","r",stdin);
    //freopen("","w",stdout);
    int n,x;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if (palin(x)) printf("%d ",x);
    }

}
