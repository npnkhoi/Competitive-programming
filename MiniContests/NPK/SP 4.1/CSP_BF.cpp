#include <bits/stdc++.h>
using namespace std;
int a[1000],i,j,n,m,s;
int main()
{
    freopen("CSP.inp","r",stdin);
    freopen("CSPBF.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++) s += (a[i]+a[j]<=m);
    cout << s;
}
