#include <bits/stdc++.h>
using namespace std;
int n;
bool ok(int x)
{
    int s=n;
    for (int i=1;i<=x;i++)
    {
        s--;
        if (s%x!=0) return 0; //cout<<x<<endl;}
        else s-=s/x;
    }
    return (s%x==0);
}
int main()
{
    //freopen("00616.inp","r",stdin);
    //freopen("00616.out","w",stdout);
    while (1)
    {
        scanf("%d",&n);
        if (n<0) break;
        //======================================
        printf("%d coconuts, ",n);
        int res=1;
        for (int i=1;i<=sqrt(n-1);i++)
        {
            if ((n-1)%i==0) if (ok((n-1)/i)) { res=max(res,(n-1)/i); continue;}
            if (ok(i)) res=max(res,i);
        }
        if (res==1) printf("no solution\n");
        else printf("%d people and 1 monkey\n",res);
    }
}
