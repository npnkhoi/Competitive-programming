using namespace std;
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, int> li;
const int N = 1e5 + 10;
const int M = 1e5 + 10;
const ll oo = 1e18 + 2;

int n, m, s, t;
long long k;
vector<li> adj[2*M];
vector<int> In[N], Out[N];
ll dist[2*M];
priority_queue<li, vector<li>, greater<li> > pq;
int main() {
    freopen("metro.inp", "r", stdin);
    freopen("metro.out", "w", stdout);
    scanf("%d%d%d%d%lld", &n, &m, &s, &t, &k);
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll c;
        scanf("%d%d%lld", &u, &v, &c);
        adj[2*i-1].pb(mp(c, 2*i));
        In[v].pb(i);
        Out[u].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n", In[i].size(), Out[i].size());
        for (int x = 0; x < In[i].size(); x++)
        for (int y = 0; y < Out[i].size(); y++) {
            int u = In[i][x], v = Out[i][y];
            adj[2*u].pb(mp(u*k+v, 2*v-1));
            //cout << 2*u << "->" << 2*v-1 << "\n";
        }
    }
    for (int i = 0; i < Out[s].size(); i++)
        adj[0].pb(mp(0, Out[s][i]*2-1));
    for (int i = 0; i < In[t].size(); i++)
        adj[In[t][i]*2].pb(mp(0, 2*m+1));

    /*for (int i = 0; i <= 2*m+1; i++) {
        printf("%3d: ", i);
        for (int j = 0; j < adj[i].size(); j++) printf("%3lld", adj[i][j].fi);
        printf("\n");
    }*/

    for (int i = 1; i <= 2*m+1; i++) dist[i] = oo;
    dist[0] = 0;
    pq.push(mp(0, 0));
    while (!pq.empty()) {
        ll d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (d > dist[u]) continue;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].se;
            ll w = adj[u][j].fi;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push(mp(dist[v], v));
            }
        }
    }
    if (dist[2*m+1] == oo) printf("-1\n");
    else printf("%lld", dist[2*m+1]);
}
