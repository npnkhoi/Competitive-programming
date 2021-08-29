#include <bits/stdc++.h>
using namespace std;
int n,m,u,v;
long long res;
vector<int> adj[100005];
long long deg[100005],f[100005];
int main()
{
    //freopen("10H.inp","r",stdin);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) f[i]=1;
    for (int u=2;u<=n;u++)
    for (int i=0;i<adj[u].size();i++)
        if ((v=adj[u][i])&&(v<u)) f[u]=max(f[u],1+f[v]);
    res=0;
    for (int i=1;i<=n;i++) deg[i]=adj[i].size();
    for (int i=1;i<=n;i++) res=max(res,deg[i]*f[i]);
    printf("%lld",res);
}
