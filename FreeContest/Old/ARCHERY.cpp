// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================
const int N=100050;
const int l1=15000;
const int l2=7000;
int n,x[N],y[N],p[N];
int res;
bool nearO(int p1, int p2)
{
    int xa=x[p1]-1000;
    int xb=x[p2]-1000;
    int ya=y[p1]+1000;
    int yb=y[p2]+1000;
    return (xa*xa+ya*ya<=xb*xb+yb*yb);
}
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    for (int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,nearO);
    res=0;
    for (int i=1;i<=min(l1,n);i++)
        for (int j=n;j>=max(n-l2+1,1);j--)
            res=max(res,(x[p[i]]-x[p[j]])*(x[p[i]]-x[p[j]])+(y[p[i]]-y[p[j]])*(y[p[i]]-y[p[j]]));
    printf("%.4f",sqrt(res));
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
