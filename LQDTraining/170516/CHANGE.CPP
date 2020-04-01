#include <bits/stdc++.h>
using namespace std;
int x,y;
bool ok(int k)
{
    int a=x,b=y;
    while (a)
    {
        int ra= a%k; int rb=b%k;
        a/=k;
        if (ra==rb) b/=k;
    }
    return (!b);
}
int main()
{
    //freopen("CHANGE.INP","r",stdin);
    //freopen("CHANGE.OUT","w",stdout);
    scanf("%d%d",&x,&y);
    for (int k=2;k<=x;k++) if (ok(k)) {printf("%d",k); return 0;}
    printf("no solution");

}

