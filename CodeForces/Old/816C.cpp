using namespace std;
#include <bits/stdc++.h>
const int  N =110;
const int oo = 1e8;
int n,m,total,scol;
bool ok;
int a[N][N],minrow[N],mincol[N];
int res = 0;
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    //freopen("test.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=max(m,n);i++) minrow[i]=mincol[i]=oo;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
        minrow[i]=min(minrow[i],a[i][j]);
        mincol[j]=min(mincol[j],a[i][j]);
    }
    for (int i=1;i<n;i++)
    for (int j=1;j<m;j++)
    if (a[i][j]-a[i+1][j]!=a[i][j+1]-a[i+1][j+1])
    {
        cout << -1;
        return 0;
    }
    res = 0;
    if (m>n)
    {
        for (int i=1;i<=n;i++) res += minrow[i];
        for (int j=1;j<=m;j++) res += a[1][j]-minrow[1];
        cout << res << endl;
        for (int i=1;i<=n;i++)
            for (int k=1;k<=minrow[i];k++) printf("row %d\n",i);
        for (int j=1;j<=m;j++)
            for (int k=1;k<= a[1][j]-minrow[1];k++) printf("col %d\n",j);
    }
    else
    {
{
        for (int i=1;i<=m;i++) res += mincol[i];
        for (int j=1;j<=n;j++) res += a[j][1]-mincol[1];
        cout << res << endl;
        for (int i=1;i<=m;i++)
            for (int k=1;k<=mincol[i];k++) printf("col %d\n",i);
        for (int j=1;j<=n;j++)
            for (int k=1;k<= a[j][1]-mincol[1];k++) printf("row %d\n",j);
    }

    }
    return 0;
}
/*
using namespace std;
#include <bits/stdc++.h>
const int  N =110;
const int oo = 1e8;
int n,m,total,scol;
bool ok;
int a[N][N],srow[N],r[N],ans[N];
int res = oo;


int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d",&n,&m);
    total = 0;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
        srow[i]+=a[i][j];
        total += a[i][j];
    }
    //for (int i=1;i<=n;i++) printf("srow %d\n",srow[i]);
    for (scol=0;scol<=total/n + 2;scol++)
    {
        //cout << "scol" << scol << endl;
        ok = 1;
        for (int i=1;i<=n&&ok;i++)
        {
            r[i]=srow[i]-scol;
            //if (scol==1) printf("r[%d] = %d\n",i,r[i]);
            if (r[i]<0 || r[i]%m ) ok=0; else r[i]/=m;
        }
        if (!ok) continue;
        for (int i=1;i<n&&ok;i++)
        for (int j=1;j<=m&&ok;j++)
            if (a[i][j]-r[i] != a[i+1][j]-r[i+1])
                ok = 0;
            //{ ok = 0; cout << i << " " << j << endl; }
        if (ok)
        {
                if (res > scol + (total-n*scol)/m)
                {
                    res =scol + (total-n*scol)/m;
                    for (int i=1;i<=n;i++) ans[i]=r[i];
                }
                //cout << "?" << scol + (total-n*scol)/m << endl;
        }

    }
    if (res==oo) cout << -1;
    else
    {
        cout << res << endl;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=ans[i];j++) printf("row %d\n",i);
        for (int j=1;j<=m;j++)
            for (int k=1;k<=a[1][j]-ans[1];k++) printf("col %d\n",j);
    }
    //cout << "ok";
    return 0;
}
*/
