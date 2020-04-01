// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================
const int N=105;
const int maxA=1e9+5;
const int md=1e9+7;
int n,a[N],b[N],f[N],m;
vector <int> d;

int id(int x)
{
    int l,r,mid;
    l=1; r=n;
    while (l<r)
    {
        mid=(l+r+1)/2;
        if (a[mid]<=x) l= mid;
        else r=mid-1;
    }
    return l;
}

//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    freopen("barcode.inp","r",stdin);
    //freopen("barcode.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    //------------------------------
    f[1]=1;
    for (int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-1])%md;
    //-----------------------------
    scanf("%d",&m);
    while (m--)
    {
        int res=1;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            b[i]=id(x);
        }
        d.clear();
        for (int i=1;i<=n;i++) d.push_back(i);
        //-----------------
        for (int i=1;i<n;i++)
        {
            if (b[i]!=d[0])
            {
                d.erase(d.begin()+1);
                res=(res+f[n-i])%md;
            }
            else d.erase(d.begin());
        }
        printf("%d\n",res);
    }
    return 0;
}
/* -----BACKUP -------------
bool ok()
{
    int maxx=a[1];
    for (int i=3;i<=n;i++)
    {
        maxx=max(maxx,a[i-2]);
        if (maxx>a[i]) return 0;
    }
    return 1;
}
void show()
{
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}
for (n=1;n<=5;n++)
    {
        int cnt=1;
        for (int i=1;i<=n;i++) a[i]=i;
        gt[0]=1; for (int i=1;i<=n;i++) gt[i]=gt[i-1]*i;
        show();
        for (int i=2;i<=gt[n];i++)
        {
            next_permutation(a+1,a+n+1);
            if (ok()) {show();
                    cnt++;}
        }
        printf("------%d\n",cnt);
    }
*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
