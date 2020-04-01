#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,a[N],res;
int main()
{
    freopen("SEQ1.inp","r",stdin);
    freopen("SEQ1.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    res=0;
    for (int x=1;x<n;x++)
    {
        int f[x+50][n-x+50];
        for (int i=0;i<=x;i++) f[i][0]=0;
        for (int j=0;j<=n-x;j++) f[0][j]=0;
        for (int i=1;i<=x;i++)
        for (int j=x+1;j<=n;j++)
        {
            f[i][j-x]=max(f[i-1][j-x],f[i][j-x-1]);
            if (a[i]<a[j]) f[i][j-x]=max(f[i][j-x],f[i-1][j-x-1]+1);
        }
        res=max(res,f[x][n-x]);
    }
    cout<<res;
}
