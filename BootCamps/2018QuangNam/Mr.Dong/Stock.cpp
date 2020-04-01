#include <bits/stdc++.h>
using namespace std;
const int ooo=-1e9;
int f[35][110][110][110],q[35],p[35][110];
int res,t,n,s,days;
int main()
{
    freopen("STOCK.inp","r",stdin);
    //freopen("STOCK.out","w",stdout);
    scanf("%d%d%d",&n,&s,&days);
    //cout<<n<<s<<days<<endl;
    for (int i=1;i<=n;i++) scanf("%d",&q[i]);
    //for (int i=1;i<=n;i++) printf("%d\n",q[i]);

    for (int d=1;d<=days;d++)
        for (int i=1;i<=n;i++) scanf("%d",&p[d][i]);
    //for (int i=1;i<=q[1];i++) cout << p[][i] << " ";
    f[0][0][0][0]=s;
    for (int i=1;i<=q[1];i++)
    for (int j=1;j<=q[2];j++)
    for (int k=1;k<=q[3];k++) f[0][i][j][k]=ooo;

    for (int d=1;d<=days;d++)
        for (int i=0;i<=q[1];i++)
        for (int j=0;j<=q[2];j++)
        for (int k=0;k<=q[3];k++)
    {
        t=ooo;
        for (int x=0;x<=q[1];x++)
        for (int y=0;y<=q[2];y++)
        for (int z=0;z<=q[3];z++)
            t=max(t,f[d-1][x][y][z]+(x-i)*p[d][1]+(y-j)*p[d][2]+(z-k)*p[d][3]-abs(x-i)-abs(y-j)-abs(z-k));
        f[d][i][j][k]=t;
    }
    res=0;
    for (int i=0;i<=q[1];i++)
    for (int j=0;j<=q[2];j++)
    for (int k=0;k<=q[3];k++) res=max(res,f[days][i][j][k]);
    cout << res;
}
