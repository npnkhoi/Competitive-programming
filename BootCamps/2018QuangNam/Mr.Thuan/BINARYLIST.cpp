using namespace std;
#include <bits/stdc++.h>
const int N=1e4+50;
const int oo=1e9+7;
int n,k,m,cnt;
int a[N];
int f[N];
bool ok()
{
    int dem=0;
    for (int i=0;i<n;i++)
        if (a[i]==0)
    {
        dem++;
        if (dem>=m) return 0;
    } else dem=0;
    return 1;
}
void minians(int k, int n)
{
    memset(a,0,sizeof(a));
    cnt=(ok());
    while (1)
    {
        int i=0;
        while ((a[i]==1)&&(i<n)) i++;
        {
            a[i]=1;
            for (int j=i-1;j>=0;j--) a[j]=0;
        }
        cnt+=ok();
        if (cnt==k)
        {
            for (int i=n-1;i>=0;i--) printf("%d ",a[i]);
            return;
        }
    }
}
void ans(int k, int n)
{
    if (n<=m||n<=20)
    {
        minians(k,n);
        return;

    }
    int s=0, i=n-m-1;
    //cout<< i << endl;
    do
    {
        i++;
        s+=f[i];
        //cout<< i << " " << s << endl;
    } while (s<k);
    for (int j=n;j>i+1;j--) printf("0 ");
    printf("1 ");
    s-=(s-f[i]);
    ans(k, i);
}
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    f[0]=1; f[m]=1;
    for (int i=1;i<m;i++)
    {
        f[i]=min(f[i-1]*2,oo);
        f[m]+=f[i];
    }
    for (int i=m+1;i<=n;i++) f[i]=min(f[i-1]+f[i-1]-f[i-m-1],oo);
    //for (int i=0;i<=n;i++) cout<< f[i] << " ";
    //cout<<endl;
    if (k>f[n]) printf("-1");
        else ans(k, n);
}
/*
//freopen("binarylist.inp","r",stdin);
    scanf("%d%d",&n,&m);
    //for (int i=n-1;i>=0;i--) printf("%d ",a[i]);
    cnt=(ok());
    cout << cnt << endl;
    while (1)
    {
        int i=0;
        while ((a[i]==1)&&(i<n)) i++;
        if (i==n)
        {
            //printf("-1");
            //return 0;
            break;
        }else
        {
            a[i]=1;
            for (int j=i-1;j>=0;j--) a[j]=0;
        }
        if (ok())
        {
            cnt+=ok();
            cout << cnt << "\t";
            for (int i=n-1;i>=0;i--) cout << a[i] << " ";
            cout<<endl;
        }
        //for (int i=n-1;i>=0;i--) printf("%d ",a[i]);
        //printf(" -- %d\n",cnt);
    }

    //for (int i=n-1;i>=0;i--) printf("%d ",a[i]);
    return 0;
*/
