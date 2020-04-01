// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int R=7;
const int C=22;
const int N=7;
const int oo=1e9;

int n,t,r,d,e;
int f[R][C][C][C][C][C];
int c[N+2], p[R+2][N+2];
int x[C+2];
int zz=1e8;
int res, mi, ma;
//==================<< END OF TEMPLATE >>========================

int buy()
{
    if (x[0]>r) return 0;
    if (f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]!=-1)
        return f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]];
    for (int i=0;i<=n;i++) cout << x[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++)
    {
        if (x[i]<0||x[i]>c[i])
        {
            f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]=-oo;
            cout << "not allowed" << endl;
            return -oo;
        }
    }
    int zz=5e8; while (zz--);
    int res=-oo;
    for (int i=1;i<=n;i++)
    {
        int change=p[x[0]][i]+d;
        x[i]++;
        res=max(res,buy()-change);
        x[0]++;
        res=max(res,buy()-change);
        x[i]--; x[0]--;
    }
    f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]=res;

    cout << "res ====== " << res << endl;
    return res;
}
int sell()
{
    if (x[0]>r) return 0;

    if (f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]!=-1)
        return f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]];
    for (int i=0;i<=n;i++) cout << x[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++)
    {
        if (x[i]<0||x[i]>c[i])
        {
            f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]=-oo;
            cout << "not allowed" << endl;
            return -oo;
        }
    }
    int zz=5e8; while (zz--);
    int res=0;
    for (int i=1;i<=n;i++)
    {
        int change=p[x[0]][i]-e;
        x[i]--;
        res=max(res,sell()+change);
        x[0]++;
        res=max(res,sell()+change);
        x[i]++; x[0]--;
    }
    f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]]=res;

    cout << "res ====== " << res << endl;
    return res;

}
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    freopen("BGAME.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d%d%d",&n,&t,&r,&d,&e);
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    for (int i=1;i<=r;i++)
        for (int j=1;j<=n;j++) scanf("%d",&p[i][j]);
    /*for (int i=1;i<=r;i++) for (int j=1;j<=n;j++) cout << p[i][j];
    int zz=2e9;
    while (zz--);*/

    res=0;
    for (int j=1;j<=n;j++)
    {
        mi=oo; ma=-oo;
        for (int i=1;i<=r;i++)
        {
            mi=min(mi,p[i][j]);
            ma=max(ma,p[i][j]);
        }
        res+=(ma-mi)*c[j];
    }
    printf("%d",t+res);
    /*memset(x,0,sizeof(x)); x[0]=1;
    memset(f,-1,sizeof(f));
    buy(); sell(); buy(); sell();
    printf("%d",t+buy());*/
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
