#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("10940.inp","r",stdin);
    //freopen("","w",stdout);
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0) break;
        if (n==1) {printf("1\n"); continue;}
        int x=1;
        while (2*x<n) x*=2;
        printf("%d\n",2*(n-x));
    }
}
