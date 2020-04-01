#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=25;
const ll oo=-1e10;
int a,b,c,tc;
ll g[N][N][N],tmp,res;
ll s(int x,int y, int u, int v, int i)
{
    ll t=g[u][v][i];
    if (x) t-=g[x-1][v][i];
    if (y) t-=g[u][y-1][i];
    if (x&&y) t+=g[x-1][y-1][i];
    return t;
}
int main()
{
    //freopen("10755.inp","r",stdin);
    //freopen("10755.out","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        scanf("%d%d%d",&a,&b,&c);
        for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
        for (int k=0;k<c;k++)
        {
            scanf("%lld",&g[i][j][k]);
            if (i>0) g[i][j][k]+=g[i-1][j][k];
            if (j>0) g[i][j][k]+=g[i][j-1][k];
            if ((i>0)&&(j>0)) g[i][j][k]-=g[i-1][j-1][k];
        }
        /*for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
        for (int k=0;k<c;k++) cout<<g[i][j][k]<<" ";
        cout<<endl;*/
        //====================
        res=0; tmp=0;
        for (int x=0;x<a;x++)
        for (int y=0;y<b;y++)
        for (int u=x;u<a;u++)
        for (int v=y;v<b;v++)
        {
            tmp=0;
            for (int i=0;i<c;i++)
            {
                //cout<<tmp<<endl;
                tmp+= s(x,y,u,v,i);
                res=max(res,tmp);
                tmp=max((ll)0,tmp);
            }
        }
        //==============================
        if (res>0)
        {
            printf("%lld\n",res);
            if (tc) cout<<endl;
            continue;
        }
        res=oo;
        for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
        for (int k=0;k<c;k++)
            res=max(res,g[i][j][k]);
        printf("%lld\n",res);
        if (tc) cout<<endl;
    }
}
