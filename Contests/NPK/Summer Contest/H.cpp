#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,a[100100],premax,res;
    //freopen("H.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    premax=a[1]; res=-1;
    for (int i=2;i<=n;i++)
    {
        premax=max(premax,a[i-1]);
        res=max(res,premax-a[i]);
    }
    if (res>0) printf("%d",res);
    else printf("Lo nang roi!");
}
