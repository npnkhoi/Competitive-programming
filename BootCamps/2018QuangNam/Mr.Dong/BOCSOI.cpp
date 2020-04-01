#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
const int N=35;
const int M=3e5+50;
const int md=111539786;
ll f[N][N][N][N][N];
int n,x[7],a[7];
int id[M];
void SetY()
{
    for (int i=0;i<n;i++)
    {
        int cnt=0, t=a[i];
        while (t)
        {
            cnt++;
            if (t%2) t--; else t/=2;
        }
        t=a[i];
        for (int i=cnt;i>=0;i--)
        {
            id[t]=i;
            //printf("id[%d]=%d\n",t,i);
            if (t%2) t--; else t/=2;
        }
    }
}
ll sol()
{
    for (int i=0;i<n;i++)
    {
        x[i]=id[a[i]];
        //cout<<x[i]<<" ";
    }
    //cout<<endl;
    if (f[x[0]][x[1]][x[2]][x[3]][x[4]]!=-1)
    {
        //cout<<f[x[0]][x[1]][x[2]][x[3]][x[4]]<<endl;
        //cout<<"------------------"<<endl;
        return f[x[0]][x[1]][x[2]][x[3]][x[4]];

    }
    ll t=0;
    for (int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        if ((a[i]%2)&&(a[j]%2))
        {
            a[i]--; a[j]--;
            t=(t+sol())%md;
            a[i]++; a[j]++;
            x[i]=id[a[i]]; x[j]=id[a[j]];
        }

        if (a[i]&&a[j])
        {
            int A=a[i], B=a[j];
            a[i]/=2; a[j]/=2;
            t=(t+sol())%md;

            a[i]=A; a[j]=B;
            x[i]=id[a[i]]; x[j]=id[a[j]];
        }
    }
    f[x[0]][x[1]][x[2]][x[3]][x[4]]=t;
    //cout<<t<<endl;
    //cout<<"------------------"<<endl;
    return t;
}
int main()
{
    freopen("BOCSOI.inp","r",stdin);
    freopen("BOCSOI.out","w",stdout);
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    SetY();
    //cout<<id[1]<<" "<<id[0]<<endl;
    memset(f,-1,sizeof(f));
    f[0][0][0][0][0]=1;
    printf("%lld",sol());
}
