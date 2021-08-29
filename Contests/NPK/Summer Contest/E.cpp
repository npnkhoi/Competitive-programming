#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,f[1010];
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=0;i<=m;i++) f[i]=i;
    //for (int i=0;i<=n;i++) cout<<f[i]<<" ";
    //cout<<endl;
    for (int i=m+1;i<=n;i++)
    {
        int tmp=n+10;
        for (int j=1;j<=m;j++) tmp=min(tmp,f[i-j]);
        f[i]=i-tmp;
    }
    //for (int i=0;i<=n;i++) cout<<f[i]<<" ";
    //cout<<endl;
    printf("%d",f[n]);
}
