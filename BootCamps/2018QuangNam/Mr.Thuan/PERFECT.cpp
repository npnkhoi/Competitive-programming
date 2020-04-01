// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================
const int N=1e5+50;
const int md=1e9;
int n,b,x,maxx,a1,f[N];
bool Greater(int x, int y)
{
    return x>=y;
}
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    freopen("","r",stdin);
    freopen("","w",stdout);
    scanf("%d%d",&n,&b);
    scanf("%d",&x);
    maxx=x; a1=x;
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        maxx=max(maxx,x);
    }
    if (b<=maxx)
    {
        printf("0\n0\n");
        return 0;
    }
    if (maxx==a1) printf("2\n");
    else printf("1\n");
    f[1]=1;
    f[2]=2;
    for (int i=3;i<=n+1;i++) f[i]=(f[i-1]+f[i-2])%md;
    printf("%d",f[n+1]);
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
