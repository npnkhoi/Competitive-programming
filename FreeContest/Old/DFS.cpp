// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================
const int md=1e9+7;
int n,a[110],f[110][110];

ll sol(int i, int j)
{
    if (i>=j) return 1;
    if (f[i][j]!=-1) return f[i][j];
    ll s=sol(i+1,j);
    for (int k=i+1;k<=j;k++)
        if (a[i]<a[k])
        s=(s+sol(i+1,k-1)*sol(k,j))%md;
    f[i][j]=s;
    return s;
}

//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    memset(f,-1,sizeof(f));
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    printf("%lld",sol(2,n));
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
