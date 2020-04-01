#include <bits/stdc++.h>
#define fi first
#define se second
const int maxM=1e5+5;
const int maxN=1e4+5;
const int MOD=1e9;
using namespace std;
struct edge
{
    int u,v;
};
typedef struct edge elist;
elist e[maxM];
vector<int> adj[2][maxN];
bool from1[maxN],to2[maxN],Free[maxN];
long long f[maxN];
int n,m;

/////////////////////////////////////////////////////
void start()
{
    freopen("BIC.INP","r",stdin);
    //freopen("BIC.OUT","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    scanf("%d%d",&e[i].u,&e[i].v);
}
void dfs(int u,int x)
{
    Free[u]=0;
    for (int v=0;v<adj[x][u].size();v++) if(Free[adj[x][u][v]]) dfs(adj[x][u][v],x);
}
void build()
{
    //for (int i=1;i<=m;i++)
       // printf("%d %d\n",e[i].u,e[i].v);
    for (int i=1;i<=m;i++)
    {
        adj[1][e[i].v].push_back(e[i].u);
        adj[0][e[i].u].push_back(e[i].v);
        //for (int i=1;i<=n;i++) printf("%d\n",adj[0][i].size());
    }
    for (int i=1;i<=n;i++) Free[i]=1;
    dfs(1,0);
    for (int i=1;i<=n;i++) from1[i]=!Free[i];
    for (int i=1;i<=n;i++) Free[i]=1;
    dfs(2,1);
    for (int i=1;i<=n;i++) to2[i]=!Free[i];
}
bool canCal(int x)
{
    bool ok=1;
    for (int i=0;i<adj[1][x].size();i++) ok=ok&&(f[adj[1][x][i]]);
    return ok;
}
void cal(int x)
{
    //printf("%d: ",x);
    for (int i=0;i<adj[1][x].size();i++)
    {
        f[x]=(f[x]+f[adj[1][x][i]])%MOD;
        //printf("%d (%d) ",adj[0][x][i],f[adj[0][x][i]]);
    }
    //printf("%d\n",f[x]);
}
int sol()
{
    if (!to2[1]) return 0;
    for (int i=1;i<=n;i++) f[i]=0;
    f[1]=1;
    //printf("reach!");
    while (1)
    {
        bool stop=1;
        if (canCal(1)) return 0;
        for (int i=2;i<=n;i++) if (from1[i]&&to2[i]&&(f[i]==0)&&canCal(i))
        {
            cal(i);
            stop=0;
        }
        if (stop) return 0;
    }
}
void finish()
{
    if (sol()) printf("%lld",f[2]);
        else printf("inf");
}
int main()
{
    start();
    build();
    for (int i=1;i<=n;i++) printf("%d %d\n",from1[i],to2[i]);
    sol();
    finish();
}
