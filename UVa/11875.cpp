#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int tc,n,a[10];
int main()
{
    //freopen("11875.inp","r",stdin);
    scanf("%d",&tc);
    for (int i=1;i<=tc;i++)
    {
        scanf("%d",&n);
        for (int j=1;j<=n;j++) scanf("%d",&a[j]);
        sort(a+1,a+n+1);
        //for (int j=1;j<=n;j++) cout<<a[j]<<" ";
        printf("Case %d: %d\n",i,a[n/2+1]);
    }
}
