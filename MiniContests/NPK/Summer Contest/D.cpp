#include <bits/stdc++.h>
#define ll long long
const ll md=1000000007;
int n,tc;
ll memo[110][110];
int a[110];
using namespace std;
long long f(int i, int j)
{
    if (memo[i][j]) return memo[i][j];
    if (i==j)
    {
        memo[i][j]=1;
        return 1;
    }
    memo[i][j]=f(i+1,j);    //mot cay
    for (int k=i+1;k<=j;k++)    //rung cay
        if (a[i]<a[k]) memo[i][j]=(memo[i][j]+f(i,k-1)*f(k,j))%md;
    return memo[i][j];

}
int main()
{
    //freopen("D.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(memo,0,sizeof(memo));
    if (n==1) printf("1\n");
    else printf("%lld\n",f(2,n));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) cout<<memo[i][j]<<"\t";
        cout<<endl;
    }



}
