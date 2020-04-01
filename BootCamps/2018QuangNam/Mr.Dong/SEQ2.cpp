#include <bits/stdc++.h>
using namespace std;
const int N=1e4+50;
int n,a[N],f[N][N],res;
int main()
{
    freopen("SEQ2.inp","r",stdin);
    freopen("SEQ2.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<n;i++)
        for (int j=n;j>i;j--)
        {
            f[i][j]=max(f[i][j+1],f[i-1][j]);
            if (a[i]<a[j]) f[i][j]=max(f[i][j],f[i-1][j+1]+1);
        }
    /*for (int i=0;i<=n+1;i++)
    {
        for (int j=0;j<=n+1;j++) cout<<f[i][j]<<" ";
        cout<<endl;
    }*/

    res=0;
    for (int i=1;i<n;i++) res=max(res,f[i][i+1]);
    cout<<res<<endl;
}
