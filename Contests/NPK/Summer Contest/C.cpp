#include <bits/stdc++.h>
#define ll long long
const int md=1000000007;
int n,f[110];
using namespace std;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    f[1]=1;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=i-1;j++) f[i]=(f[i]+f[j]*f[i-j])%md ;
    printf("%d",f[n]);
}
