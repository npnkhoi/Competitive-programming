using namespace std;
#include <stdio.h>
#include <vector>
#include <queue>
int n,m;
const int N = 1e5 + 50;
const int oo = 1e6;
vector<int> adj[N];
vector<int> d(N,oo);
queue<int> q;
void bfs()
{
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if (d[v]==oo) d[v]=d[u]+1, q.push(v);
        }
    }
}
int main()
{
    freopen("broadcast.inp","r",stdin);
    freopen("broadcast.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
    }
    q.push(0); d[0] = 0;
    bfs();
    if (d[n-1]==oo) printf("-1"); else printf("%d",d[n-1]);
    return 0;
}
