#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,x,y,u,v;
long long a[1010][1010],sum[1010][1010];
long long res;
void start()
{
    //freopen("MINCUT.INP","r",stdin);
    //freopen("MINCUT.OUT","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    //cout<<n<<m<<k;
    for (i=1;i<=m;i++)
    for (j=1;j<=n;j++) scanf("%lld",&a[i][j]);
}
void build()
{
    for (i=1; i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
            //cout<<sum[i][j]<<"\t";
        }
        //cout<<endl;
    }
}

long long s(int x,int y,int u,int v)
{
    return sum[u][v]+sum[x-1][y-1]-sum[x-1][v]-sum[u][y-1];
}
void sol()
{
    //cout<<k<<endl;
    res=s(1,1,m,n);
    scanf("%d%d%d%d",&x,&y,&u,&v);
    //printf("%d %d %d %d\n",x,y,u,v);
    long long val=(s(x,y,u,v)+1)/2;
    //printf("val=%lld\n",val);
    //======================
    int l=y,r=v,mid;
    while (l<r)
    {
        //cout<<l<<" "<<r<<endl;
        mid=(l+r)/2;
        //cout<<s(x,mid,u,v)<<endl;
        if (s(x,mid,u,v)<=val) {r=mid;}
        else {l=mid+1;}
    }
    //cout<<l<<endl;
    res=min(res,abs(s(x,y,u,v)-2*s(x,l,u,v)));
    //=========================
    //cout<<"--------------"<<endl;
    l=x;r=u;
    while (l<r)
    {
        //cout<<l<<" "<<r<<endl;
        mid=(l+r)/2;
        if (s(mid,y,u,v)<=val) r=mid;
        else l=mid+1;
    }
    //cout<<l<<endl;
    res=min(res,abs(s(x,y,u,v)-2*s(l,y,u,v)));
    printf("%lld\n",res);
}
int main()
{
    start();
    build();
    //cout<<k<<endl;
    for (int i=1;i<=k;i++) sol();
}
