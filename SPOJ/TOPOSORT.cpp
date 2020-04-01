using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <set>
set<int> data;
int n, m;
const int N = 1e4 + 50;
vector<int> adj[N], ans;
bool v[N];
int u,t,cnt, into[N], pos[N];
void dfs(int u)
{
    if (v[u]) return;
    //cout << u << endl;
    v[u] = 1;
    pos[u] = ans.size(); ans.push_back(u);
    for (int i = 0; i < adj[u].size(); i++) dfs(adj[u][i]);
}

int main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d %d",&n, &m);
    while (m--)
    {
        scanf("%d%d",&u,&t);
        into[t]++;
        adj[u].push_back(t);
        //cout << u << " " << t << "\n";
    }
    for (int i = 1; i <= n; i++) if (!into[i]) data.insert(i);

    while (!data.empty())
    {
        int u = *data.begin();
        data.erase(u);
        ans.push_back(u);
        for (int i = 0; i < adj[u].size(); i++)
        {
            into[adj[u][i]] --;
            if (!into[adj[u][i]]) data.insert(adj[u][i]);
        }
    }
    if (ans.size() != n) cout << "Sandro fails.";
        else for (int i = 0; i < n; i++) cout << ans[i] << " ";
    //-------------------------------------

}
