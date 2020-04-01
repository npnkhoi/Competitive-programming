#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 50;
const int oo = 1e9;
vector<int> x, y;
int d[N];
int n, m, k, tx, ty;
vector<int> adj[N], same[N];
queue<int> q;
bool v[N];
void Push(int u, int dd)
{

    if (v[u]) return;
    //cout << u << " " << dd << endl;
    q.push(u);
    d[u] = dd;
    v[u] = 1;
    for (int i = 0; i < same[u].size(); i++)
    Push(same[u][i], d[u]);
}
void bfs()
{
    memset(v, 0, sizeof v);
    for (int i = 1; i <= k + 1; i++) d[i] = oo;
    Push(0, 0);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = 0; i < same[u].size(); i++)
        Push(same[u][i], d[u]);
        for (int i = 0; i < adj[u].size(); i++)
        Push(adj[u][i], d[u]+1);
    }
}
int main()
{
    freopen("test.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d %d", &n, &m, &k);
    x.push_back(1);
    y.push_back(1);
    bool dich = 0;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d %d", &tx, &ty);
        if (tx != 1 || ty != 1)
        {
            x.push_back(tx);
            y.push_back(ty);
        }
        if (tx == n && ty == m) dich = 1;
    }
    if (!dich) x.push_back(n), y.push_back(m);
    else k--;
    for (int i = 0; i < k; i++)
        for (int j = i+1; j <= k; j++)
    if (i != j)
    if (abs(x[i]-x[j]) + abs(y[i]-y[j]) == 1)
        if (j<k || (dich))
    {
        same[i].push_back(j);
        same[j].push_back(i);
    }   else
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
        else if  (abs(x[i] - x[j]) <= 2 || abs(y[i] - y[j]) <= 2)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    /*for (int i = 0; i <= k; i++)
    {
        for (int j=0; j<same[i].size();j++) cout << same[i][j];
            cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= k; i++)
    {
        for (int j=0; j<adj[i].size();j++) cout << adj[i][j];
            cout << endl;
    }*/
    bfs();
    if (d[k] == oo) cout << -1;
    else cout << d[k];

    return 0;
}
/**/
