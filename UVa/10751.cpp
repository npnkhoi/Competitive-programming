#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("10751.inp","r",stdin);
    //freopen("","w",stdout);
    int tc,n;
    scanf("%d ",&tc);
    while (tc--)
    {
        scanf("%d ",&n);
        if (n==1) printf("0.000\n\n");
        else if (n==2) printf("4.000\n\n");
        else
        {
            float x=n;
            printf("%.3f\n\n",(4*x-4)+sqrt(2)*(x-2)*(x-2));
        }
    }
}
