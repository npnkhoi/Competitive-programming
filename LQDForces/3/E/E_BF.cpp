#include<bits/stdc++.h>
using namespace std;

#define ii pair < int , int >
#define fi first
#define se second
#define pb push_back
#define FOR(i,x,n) for(int i = x ; i <= n ; i++)

const int N = 1e5 + 5;
map < int , int > m[N];
int n , x , y , u , v;
int cnt[N] , d[N];
vector < int > g;

int main()
{
    // freopen("E.inp", "r" , stdin);
    // freopen("E.ans", "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while (tc --) {
        cin >> n;
        
        FOR(i, 1, n) m[i].clear();
        g.clear();
        memset(cnt, 0, sizeof cnt);

        FOR(i , 1 , n - 1)
        {
            cin >> x >> y;
            m[x][y] = true;
            m[y][x] = true;
            cnt[x]++;
            cnt[y]++;
        }
        FOR(i , 1 , n)
            cin >> d[i];
        g.pb(d[1]);
        bool flag = 1;
        FOR(i , 2 , n)
        {
            while(!g.empty() && cnt[g[g.size() - 1]] == 0)
                g.pop_back();
            if(g.empty())
            {
                cout << "NO";
                exit(0);
            }
                u = g[g.size() - 1];
                v = d[i];
                if(m[u][v] == true)
                {
                    cnt[u]--;
                    cnt[v]--;
                    m[u][v] = false;
                    m[v][u] = false;
                }
                else
                {
                    flag = 0;
                }
                g.pb(v);
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}

