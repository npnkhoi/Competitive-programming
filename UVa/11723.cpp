#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc=0,r,n;
    while (++tc)
    {
        scanf("%d%d",&r,&n);
        if ((r==0)&&(n==0)) break;
        printf("Case %d: ",tc);
        int res=(r-1)/n;
        if (res<=26) printf("%d\n",res);
        else printf("impossible\n");
    }
}
