// Think carefully >>>>>> Are you ready ??!!!!!!!!

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define ll long long
using namespace std;
//==================<< END OF TEMPLATE >>========================
int m,n,a[100050];

//--------------<<ENF OF VARIABLES DECLARATION >>-----------------
int main()
{
    //freopen("B.inp","r",stdin);
    freopen("","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int i;
    for (i=n;i>=1;i--) if (a[i]<m+i-n) break;
    if (i==0) printf("-1\n");
    else
    {
        a[i]++;
        for (int j=i+1;j<=n;j++) a[j]=a[i]+j-i;
        for (int i=1;i<=n;i++) printf("%d ",a[i]);
    }
    return 0;
}

// Accepted in one hit, or be a silly dog :))
/* -----BACKUP -------------

*/
