#include <stdio.h>
#include <string.h>
#define ll long long
const int N=30;
const int md=111539786;
ll f[N][N][N][N][N];
int n,x[7];
ll sol(int x[])
{
    printf("%d %d %d %d %d\n",x[0],x[1],x[2],x[3],x[4]);
    if (f[x[0]][x[1]][x[2]][x[3]][x[4]]>-1) return f[x[0]][x[1]][x[2]][x[3]][x[4]];
    ll t=0;
    for (int i=0;i<n;i++)
        if ((x[i]%2)&&(x[(i+1)%n]%2))
        {
            x[i]--; x[(i+1)%n]--;
            t=(t+sol(x))%md;
            x[i]++; x[(i+1)%n]++;
        }
    for (int i=0;i<n;i++)
        if (x[i]&&x[(i+1)%n])
    {
        int a=x[i]-x[i]/2;
        int b=x[(i+1)%n]-x[(i+1)%n]/2;
        x[i]/=2;
        x[(i+1)%n]/=2;
        t=(t+sol(x))%md;
        x[i]+=a; x[(i+1)%n]+=b;
    }
    f[x[0]][x[1]][x[2]][x[3]][x[4]]=t;
}
int main()
{
    freopen("BOCSOI.inp","r",stdin);
    //freopen("BOCSOI.out","w",stdout);
    scanf("%d",&n);
    memset(x,0,sizeof(x));
    for (int i=0;i<n;i++) scanf("%d",&x[i]);
    memset(f,-1,sizeof(f));
    f[0][0][0][0][0]=1;
    printf("%lld",sol(x));
}
//=========================================================
#include <stdio.h>
#include <iostream>
#include <string.h>
#define ll long long
using namespace std;
const int N=16;
const int md=111539786;
ll f[N][N][N][N][N][2][2][2][2][2];
int deg[7];
int n,x[7];
int a[7];
ll val()
{
    return f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]][x[8]][x[9]];
}
ll sol()
{
    //printf("%d %d %d %d %d\n",x[0],x[1],x[2],x[3],x[4]);
    if (val()>-1) return val();
    ll t=0;
    //cout<<1;
    for (int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        if ((x[i+n])&&(x[j+n]))
        {
            int a=(x[i]==1); int b=(x[j]==1);
            x[i]+=a; x[j]+=b;
            x[i+n]--; x[(i+1)%n+n]--;

            t=(t+sol())%md;

            x[i]-=a; x[j]-=b;
            x[i+n]++; x[j+n]++;
        }
    }

    for (int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        if (x[i]<=deg[i]&&x[j]<=deg[j])
        {
            x[i]++; x[j]++;
            x[i+n]=a[i]&(1<<x[i]);
            x[j+n]=a[j]&(1<<x[j]);

            t=(t+sol())%md;

            x[i]--; x[j]--;
            x[i+n]=a[i]&(1<<x[i]);
            x[j+n]=a[j]&(1<<x[j]);
        }
    }

    f[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]][x[8]][x[9]]=t;
}
int main()
{
    freopen("BOCSOI.inp","r",stdin);
    //freopen("BOCSOI.out","w",stdout);
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++) scanf("%d",&a[i]);

    for (int i=0;i<n;i++)
    {
        int tmp=a[i];
        int cnt=0;
        while (tmp,cnt++) tmp/=2;
        deg[i]=cnt-1;
        //cout<<deg[i]<<" ";
    }
    memset(f,-1,sizeof(f));
    cout<<1;
    for (int i=0;i<n;i++) x[i+n]=a[i]%2;
    f[0][0][0][0][0][a[0]%2][a[1]%2][a[2]%2][a[3]%2][a[4]%2]=1;
    printf("%lld",sol());
}

