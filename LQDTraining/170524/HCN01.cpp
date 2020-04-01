#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1010][1010],h[1010],l[1010],r[1010],res,n,m;
int main()
{
    //freopen("HCN01.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&m,&n);
    //cout<<m<<" "<<n<<endl;
    for (int j=1;j<=n;j++) h[j]=0;
    //cout<<m<<" "<<n<<endl;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    //cout<<m<<" "<<n<<endl;
    //====================
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            {
                if (a[i][j]) h[j]++; else h[j]=0;
                //cout<<i<<j<<endl;
            }
        //====================
        for (int j=1;j<=n;j++)
        {
            l[j]=j;
            //cout<<l[j]<<endl;
            while ((l[j]>1)&&(h[l[j]-1]>=h[j])) l[j]=l[l[j]-1];
            //cout<<i<<j<<endl;
        }
        for (int j=n;j>=1;j--)
        {
            r[j]=j;
            while ((r[j]<n)&&(h[j]<=h[r[j]+1])) r[j]=r[r[j]+1];
            //cout<<i<<j<<endl;
        }
        //====================
        //for (int j=1;j<=n;j++) printf("%d %d %d\n",&h[j],&l[j],&r[j]);
        for (int j=1;j<=n;j++)
            res=max(res,h[j]*(r[j]-l[j]+1));
    }
    printf("%d",res);
}
