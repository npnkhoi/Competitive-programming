#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=150;
const int ooo=-1000;
int a[N][N],res,t,n;
int main()
{
    //freopen("00108.inp","r",stdin);
    //freopen("00108.out","w",stdout);
    while (scanf("%d",&n)!=EOF)
{   res=ooo;
    //cout<<res<<endl;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
        //cout<<a[i][j]<<endl;
        res=max(res,a[i][j]);
        //cout<<res<<endl;
        if (j) a[i][j]+=a[i][j-1];
    }
    for (int l=0;l<n;l++)
    for (int r=l;r<n;r++)
    {
        t=0;
        for (int i=0;i<n;i++)
        {
            t+= a[i][r];
            if (l) t-=a[i][l-1];
            if (t<0) t=0;
            else res=max(res,t);
        }
    }
    printf("%d\n",res);
}
}
