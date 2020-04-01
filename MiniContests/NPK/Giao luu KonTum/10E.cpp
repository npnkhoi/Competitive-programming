#include <bits/stdc++.h>
using namespace std;
int n,u,v;
vector<int> adjL[100005];
int f[100005];
int res;
bool Free[100005];
void dfs(int u)
{
    //cout<<"dfs "<<u<<endl;
    Free[u]=0;
    for (int i=0;i<adjL[u].size();i++)
    {
        int v=adjL[u][i];
        if (Free[v])
        {
            dfs(v);
            f[u]+=f[v];
            //cout<<u<<"<-"<<v<<":"<<f[u]<<endl;
        }
    }
}
int main()
{
    //freopen("10E.inp","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&f[i]);
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    for (int i=1;i<=n;i++) Free[i]=1;
    dfs(1);
    res=0;
    for (int i=1;i<=n;i++) res=max(res,f[i]);
    printf("%d\n",res);
    //for (int i=1;i<=n;i++) printf("%d\t",f[i]);
}
