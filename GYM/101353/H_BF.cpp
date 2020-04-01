/* <3 <3 <3 */
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair <int,ll>
#define iii pair <ii,int>
#define fi first
#define se second
#define pb push_back

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;
const int nmax=1e5+9;
const int MOD = 1000000007;

int Case,n;
ll a[nmax];
ll num[nmax];
ll t[nmax];
ll ans [nmax];
vector <ii> v[nmax];

ll dfs(int u,int p)
{
    num[u]=1;
    t[u]=0;
    for (int i=0;i<v[u].size();i++)
    {
        int e = v[u][i].fi;
        ll ue=v[u][i].se;
        if (e!=p)
        {
            a[e]=ue;
            t[u]+=a[e];
            num[u]+=dfs(e,u);
            t[u]+=t[e];
            t[u]%=MOD;
        }
    }
    return num[u];
}

ll sol(int u,int p)
{
    ans[u]=0;
    for (int i=0;i<v[u].size();i++)
    {
        int e = v[u][i].fi;
        if (e==p)
            continue;
        ans[u]+=(((a[e]*(num[e]*(num[u]-num[e]))%MOD)%MOD
                 +sol(e,u))%MOD
                 +(t[e]%MOD*(num[u]-num[e])))%MOD;
        ans[u]%=MOD;
    }
    return ans[u]%MOD;
}
int main()
{
    freopen("H.inp","r",stdin);
    freopen("H.ans","w",stdout);
    scanf("%d",&Case);
    for (int CASE=1;CASE<=Case;CASE++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            v[i].clear();
        for (int i=1;i<n;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            v[x].pb(ii(y,w));
            v[y].pb(ii(x,w));
        }
        dfs(1,0);
        sol(1,0);
        ll res = 0;
        for (int i=1;i<=n;i++)
        {
            res+=ans[i]%MOD;
            res%=MOD;
        }
        //printf("Case %d: %I64d\n",CASE,res);
        cout << ans[1] << "\n";
    }
    return 0;
}
