#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=150;

ll a[N][N],p,p0,s,s0;
int TC,tc,n,m,k,i,j;


ll sum(int x, int y, int u, int v)
{
    ll t=a[u][v];
    if (x&&y) t+=a[x-1][y-1];
    if (x) t-=a[x-1][v];
    if (y) t-=a[u][y-1];
    return t;
}
int main()
{
    //freopen("11951.inp","r",stdin);
    //freopen("00108.out","w",stdout);
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
{   scanf("%d%d%d",&n,&m,&k);
    s=0; p=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
        if (j) a[i][j]+=a[i][j-1];
        if (i) a[i][j]+=a[i-1][j];
        if (i&&j) a[i][j]-=a[i-1][j-1];
    }
    /*for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++) cout<<a[i][j]<<"\t";
        cout<<endl;
    }*/
    //===================================
    for (int l=0;l<m;l++)
    for (int r=l;r<m;r++)
    {
        //cout<<l<<" "<<r<<"-------------"<<endl;
        i=0; s0=0; p0=0;
        for (int j=0;j<n;j++)
        {
            while ((i<=j)&&(sum(i,l,j,r)>k)) i++;
            //cout<<i<<" "<<j<<" "<<sum(i,l,j,r)<<endl;
            if (i>j) continue;
            if (j-i+1>s0)
            {
                s0=j-i+1;
                p0=sum(i,l,j,r);
            }
                else if (j-i+1==s0) p0=min(p0,sum(i,l,j,r));
        }
        if (s0*(r-l+1)>s)
        {
            s=s0*(r-l+1);
            p=p0;
        }
        else if (s0*(r-l+1)==s) p=min(p,p0);
    }
    printf("Case #%d: %lld %lld\n",tc,s,p);
}
}
