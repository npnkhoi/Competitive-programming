#include <bits/stdc++.h>
using namespace std;
int n,x,v,f[100005],res;
bool Free[100005];
vector<int> adj[100005];
void dfs(int u)
{
    Free[u]=0;
    for (int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if (Free[v])
        {
            f[v]=f[u]+1;
            dfs(v);
        }
    }
}
int main()
{
    //freopen("10K.inp","r",stdin);
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        adj[x].push_back(i);
    }
    for (int i=1;i<=n;i++) Free[i]=1;
    f[1]=1; dfs(1);
    res=1;
    for (int i=1;i<=n;i++) res=max(res,f[i]);
    printf("%d",res);
}
