
// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define fi first
#define se second
const double oo=1e9;
using namespace std;
//==================<< END OF TEMPLATE >>========================
int n;
ii p[10];
double memo[1<<10][12];
double res;
int trace[1<<10][12];
int endpoint;
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
double dist(ii a, ii b)
{
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}
double cost(int mask, int x)
{
    if ((1<<x)&mask==0) return oo;
    //printf("cost(%d,%d)\n",mask,x);
    if (memo[mask][x]>-1) return memo[mask][x];
    if (__builtin_popcount(mask)==1)
    {
        memo[mask][x]=0;
        return 0;
    }
    double res=oo;
    for (int i=0;i<n;i++)
    if ((i!=x)&&((mask&1<<i)>0))
        if (res > (cost(mask^(1<<x),i)+dist(p[i],p[x])+16))
    {
        res=cost(mask^(1<<x),i)+dist(p[i],p[x])+16;
        trace[mask][x]=i;
    }
    memo[mask][x]=res;
    //cout << res << endl;
    return res;
}
void ShowSol(int mask, int x)
{
    if (__builtin_popcount(mask)==1) return;
    ShowSol(mask^(1<<x),trace[mask][x]);
    ii a=p[trace[mask][x]], b=p[x];
    //printf("%d %d\n",trace[mask][x],x);
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
            a.fi,a.se,b.fi,b.se,dist(a,b)+16);
}
//-------------------<< END OF FUNCTIONS >>---------------------
int main()
{
    //freopen("00216.inp","r",stdin);
    //freopen("","w",stdout);
    int tc=0;
    while (scanf("%d",&n)!=EOF,++tc)
    {
        if (n==0) break;
        for (int i=0;i<n;i++)
            scanf("%d%d",&p[i].fi,&p[i].se);
        res=oo;
        memset(memo,-1,sizeof(memo));
        for (int i=0;i<n;i++)
        if (res>cost((1<<n)-1,i))
        {
            res=cost((1<<n)-1,i);
            endpoint=i;
        }
        //------------------
        printf("**********************************************************\n");
        printf("Network #%d\n",tc);
        //printf("endpoint %d\n",endpoint);
        ShowSol((1<<n)-1,endpoint);
        printf("Number of feet of cable required is %.2f.\n",res);
    }

    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
