#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[10050],s,res;
int main()
{
    //freopen("10684.inp","r",stdin);
    //freopen("","w",stdout);
    while (1)
    {
        //cout<<1;
        scanf("%d",&n);
        if (n==0) break;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        s=0; res=0;
        for (int i=1;i<=n;i++)
        {
            s+=a[i];
            if (s<0) s=0; else res=max(res,s);
        }
        if (res>0) printf("The maximum winning streak is %d.\n",res);
        else printf("Losing streak.\n");
    }

}
