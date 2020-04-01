#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
#define task "snum"
#define fi first
#define se second

const int N = 1e5 + 5;
int m, n, s, vtx, scc;
int num[N], low[N], root[N], id[N], degIn[N];
vector<int> adj[N], graph[N], ans;
vector<pair<int, int> > e;
stack<int> st;
bool onStack[N];
void tarjan(int u) {
    num[u] = low[u] = ++ vtx;
    st.push(u); onStack[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (!num[v]) tarjan(v);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        scc ++; root[scc] = u;
        while (1) {
            int v = st.top(); st.pop();
            onStack[v] = 0;
            id[v] = scc;
            //cerr << v << " ";
            if (u == v) break;
        }
        //cerr << id[u] << " " << root[id[u]] << "\n";
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) if (!num[i]) tarjan(i);

    for (int u = 1; u <= n; u++)
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (id[u] != id[v])
            e.push_back(make_pair(id[u], id[v]));
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++)
    if (i == 0 || e[i] != e[i+1]) {
        graph[e[i].fi].push_back(e[i].se);
        //cerr << e[i].fi << " " << e[i].se << "\n";
        degIn[e[i].se] ++;
    }
    for (int i = 1; i <= scc; i ++)
    if (degIn[i] == 0 && i != id[s]) {
        ans.push_back(root[i]);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i], s);
    }
}

