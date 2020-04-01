using namespace std;
#include <stdio.h>
#include <string.h>
const int N = 1e6 + 50;
int a[N],s[N];
int n,m;
long long res;
int main()
{
    freopen("CSP.inp","r",stdin);
    freopen("CSP.out","w",stdout);
    memset(s,0,sizeof(s));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]), s[a[i]]++;
    for (int i=1;i<=(int)1e6+10;i++)  s[i]+=s[i-1];
    for (int i=1;i<=n;i++) if (a[i]<=m)
    {
        res+=1LL*s[m-a[i]];
        if (a[i]<=m-a[i]) res--;
    }
    printf("%lld",res/2);
}
