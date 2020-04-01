#include <bits/stdc++.h>

#define ll long long

using namespace std;
const int N=10000;
string x,y,z;
int m,n,k,fxy[N][N],fxz[N][N],maxy,maxz,res;
int main()
{
    freopen("DoanConChung3.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    cin>>x; cin>>y; cin>>z;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            fxy[i][j]=max(fxy[i][j-1],fxy[i-1][j]);
            if (x[i]==y[j]) fxy[i][j]=max(fxy[i][j],fxy[i-1][j-1]+1);

        }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=k;j++)
        {
            fxz[i][j]=max(fxz[i][j-1],fxz[i-1][j]);
            if (x[i]==z[j]) fxz[i][j]=max(fxz[i][j],fxz[i-1][j-1]+1);
        }
    res=0;
    for (int i=1;i<=m;i++)
    {
        maxy=0; maxz=0;
        for (int j=1;j<=n;j++) maxy=max(maxy,fxy[i][j]);
        for (int j=1;j<=k;j++) maxz=max(maxz,fxz[i][j]);
        res=min(maxy,maxz);
    }
    printf("%d",res);
}
