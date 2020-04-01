#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=250;
const int M=25;
const int D=25;
int n,m,Q,q,d,a[N],tc;
ll f[N][M][D];
void xuat()
{
    //cout<<"hi";
    for (int k=0;k<d;k++)
    {
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=m;j++) printf("%5d",f[i][j][k]);
            cout<<endl;
        }
        cout<<endl;
    }
}
void sol()
{
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            for (int k=0;k<d;k++)
    {

        f[i][j][k]+=f[i-1][j][k];
        ll subk=(k-a[i])%d; if (subk<0) subk+=d;
        if (j) f[i][j][k]+=f[i-1][j-1][subk];
    }
    //xuat();
    printf("QUERY %d: %lld\n",q,f[n][m][0]);
}
int main()
{
    //freopen("10616.inp","r",stdin);
    //freopen("10616.out","w",stdout);
    tc=0;
    while (++tc)
    {
        scanf("%d%d",&n,&Q);
        if ((n==0)&&(Q==0)) break;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("SET %d:\n",tc);
        for (q=1;q<=Q;q++)
        {
            scanf("%d%d",&d,&m);
            sol();
        }
        //getchar();
    }
}
