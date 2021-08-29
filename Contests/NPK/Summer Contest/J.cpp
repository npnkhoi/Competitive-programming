#include <bits/stdc++.h>
#define ll long long
const int md=1000000007;
using namespace std;
int n,m,k,p,u,v;
ll res;
vector<int> a;
int pre[15];

void union_(int u,int v)
{
    while (pre[u]>0) u=pre[u];
    while (pre[v]>0) v=pre[v];
    //int ru=root(u), rv=root[v];
    if (u!=v)
    {
        if (pre[u]<pre[v])
        {
            pre[u]+=pre[v];
            pre[v]=u;
        }
        else
        {
            pre[v]+=pre[u];
            pre[u]=v;
        }
    }

}
int main()
{
    //freopen("J.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    memset(pre,-1,sizeof(pre));
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        union_(u,v);
    }
    k=0;
    for (int i=1;i<=n;i++) if (pre[i]<0)
    {
        k++;
        a.push_back(-pre[i]); //cout<<-pre[i]<<endl;
    }
    if (m!=n-k) {printf("0"); return 0;}
    res=0; p=1;
    for (int i=0;i<k;i++) p=(p*a[i]*a[i])%md;
    //cout<<p<<endl;
    for (int i=0;i<k-1;i++)
        for (int j=i+1;j<k;j++)
        res=(res+p/(a[i]*a[j]))%md;
    for (int i=2;i<=k-2;i++) res=(res*i)%md;
    printf("%lld",res);
}
