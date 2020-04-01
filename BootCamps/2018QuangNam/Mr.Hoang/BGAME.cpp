// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================

int sol(int x[])
{
    if (x[0]==r) return 0;
    if (f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]!=-1)
        return f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]];
    for (int i=1;i<=n;i++)
    {
        if (x[i]<0||x[i]>c[i]) return ooo;
    }

    res=0;
    for (int i=1;i<=n;i++)
    {
        change=p[x[0]][i]+d;
        x[i]++;
        res=max(res,sol(x)-change);
        x[0]++;
        res=max(res,sol(x)-change);
        x[i]--; x[0]--;
        //--------------
        change=p[x[0]]-e;
        x[i]--;
        res=max(res,sol(x)+change);
        x[0]++;
        res=max(res,sol(x)+change);
        x[i]--; x[0]--;
    }
    f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]=res;
    return res;
}
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d%d%d",&n,&t,&r,&d,&e);
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    for (int i=1;i<=r;i++)
        for (int j=1;j<=n;j++) scanf("%d",&p[i][j]);

    memset(x,0,sizeof(x));
    printf("%d",sol(x));
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
