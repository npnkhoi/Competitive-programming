#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,t;
bool a[25][25];
int f[1100000],nguoi[1100000];
void xuat()
{
    for (int i=0;i<1<<n;i++) cout<<f[i]<<" ";
    cout<<endl;
}
int main()
{
    //freopen("10A.inp","r",stdin);
    scanf("%d",&t);
    while (t--)
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) a[i][j]=(i==j);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        u--;v--;
        a[u][v]=1;
        a[v][u]=1;
    }

    for (int i=0;i<n;i++)
    {
        nguoi[i]=0;
        for (int j=0;j<n;j++) if (a[i][j]) nguoi[i]+=1<<j;
        //cout<<"nguoi"<<i<<": "<<nguoi[i]<<endl;
    }
    f[0]=0;
    for (int i=1;i<(1<<n);i++) f[i]=n+1;
    for (int i=1;i<(1<<n);i++)
    {
        for (int j=0;j<n;j++)
        {
            f[i]=min(f[i-(i&nguoi[j])]+1,f[i]);
            //printf("%d-%dAND%d=%d\t",i,i,nguoi[j],i-i&&nguoi[j]);
        }
        //xuat();
    }
    printf("%d\n",f[(1<<n)-1]);
}
}
