
// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define fi first
#define se second
const int oo=1e9;
const int N=12;
using namespace std;
//==================<< END OF TEMPLATE >>========================
ii p[N];
int memo[1<<N][N];
int res;
int m,n;
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int dist(ii a, ii b)
{
    return abs(a.fi-b.fi)+abs(a.se-b.se);
}
int dp(int mask, int x)
{
    if ((1<<x)&mask==0) return oo;
    if (memo[mask][x]>-1) return memo[mask][x];
    if (mask==(1<<n)-1) return dist(p[x],p[0]);

    int res=oo;
    for (int i=0;i<n;i++)
    if ((i!=x)&&((mask&1<<i)==0))
        res=min(res,dp(mask|(1<<i),i)+dist(p[i],p[x]));
    memo[mask][x]=res;
    //cout << res << endl;
    return res;
}
//-------------------<< END OF FUNCTIONS >>---------------------
int main()
{
    //freopen("10496.inp","r",stdin);
    //freopen("","w",stdout);
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        int dd;
        scanf("%d%d",&dd,&dd);
        scanf("%d%d",&p[0].fi,&p[0].se);
        scanf("%d",&n); n++;
        for (int i=1;i<n;i++)
            scanf("%d%d",&p[i].fi,&p[i].se);
        res=oo;
        memset(memo,-1,sizeof(memo));
        //cout << 1;
        printf("The shortest path has length %d\n",dp(1,0));
    }
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
