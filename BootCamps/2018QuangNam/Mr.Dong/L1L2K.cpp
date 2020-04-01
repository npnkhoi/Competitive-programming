#include <bits/stdc++.h>

#define ll long long

using namespace std;
const int N=1e7;

int n,k,a[N],b[N];
int h[N];
int res;

void sol1()
{
    int f[n+50][n+50];
    for (int i=1;i<=n;i++) b[i]=i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if (abs(a[i]-b[j])<=k) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    printf("%d\n",f[n][n]);
}
void xuat()
{
    for (int i=1;i<=res;i++) cout<<h[i]<<" ";
    cout<<endl;

}
void sol2()
{
    int cnt=0;
    for (int i=1;i<=n;i++)
        for (int j=2*k;j>=0;j--)
        {
            cnt++;
            b[cnt]=a[i]+j-k;
        }
    //for (int i=1;i<=cnt;i++) cout<<b[i]<<endl;
    h[1]=b[1]; res=1;
    for (int i=2;i<=cnt;i++) if (b[i]>=1&&b[i]<=n)
    {
        if (b[i]>h[res])
        {
            res++;
            h[res]=b[i];
        }
        else
        {
            int l=1, r=res;
            while (l<r)
            {
                int mid=(l+r)/2;
                if (h[mid]>b[i]) r=mid;
                else l=mid+1;
            }
            if ((l==1||h[l-1]<b[i])&&b[i]<h[l]) h[l]=b[i];
        }
        //xuat();
    }
    printf("%d\n",res);
}
int main()
{
    freopen("L1L2K.inp","r",stdin);
    freopen("L1L2K.out","w",stdout);
    int tc;
    //scanf("%d",&tc);
    //while (tc--)
    {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        if (n<=10000) sol1();
        else
            sol2();
    }
}
