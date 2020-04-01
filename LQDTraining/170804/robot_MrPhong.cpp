#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i = a, _key = b; i <= _key; ++i)
#define fordec(i,a,b) for(int i = a, _key = b; i >= _key; --i)
#define fori(i,n) for(int i = 0, _key = n; i < _key; ++i)
#define ford(i,n) for(int i = n - 1; i >= 0; --i)
#define forvct(i,v) for(int i = 0, _key = v.size(); i < _key; ++i)
#define sqr(x) ((ll)x) * (x)
#define task "robot"
#define st first
#define nd second
#define m_p make_pair
#define p_b push_back
#define p_f push_front
#define pp_b pop_back
#define pp_f pop_front
#define sn string::npos
#define heap priority_queue
#define ll long long
#define db double
#define str string
#define nn 100010

using namespace std;

const ll oo = 1000000000000000000LL;

#define pii pair<int,int>
#define pli pair<ll,int>

int n, m;
vector<pii > adj[nn];
heap<pli, vector<pli >, greater<pli > > hp;
ll d[nn], h[nn], x;

void enter()
{
    cin >> n >> m >> x;
    forinc(i,1,n) cin >> h[i];
    forinc(i,1,m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].p_b(m_p(v,w));
        adj[v].p_b(m_p(u,w));
    }
}

void process()
{
    forinc(i,2,n) d[i] = oo;
    hp.push(m_p(0,1));
    while (!hp.empty())
    {
        int u = hp.top().nd;
        if (u == n)
        {
            cout << d[n] + h[n] - max(0LL,x-d[n]);
            return;
        }
        if (hp.top().st != d[u])
        {
            hp.pop();
            continue;
        }
        hp.pop();
        int t = max(0LL,x - d[u]);
        forvct(j,adj[u])
        {
            int v = adj[u][j].st, w = adj[u][j].nd, c = w;
            if (t < w)
            {
                if (w > h[u]) continue;
                c += w - t;
            }
            else
            if (t - w > h[v]) c += t - w - h[v];
            if (d[v] <= d[u] + c) continue;
            d[v] = d[u] + c;
            hp.push(m_p(d[v],v));
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //srand(time(NULL));
    freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    enter();
    process();
}
