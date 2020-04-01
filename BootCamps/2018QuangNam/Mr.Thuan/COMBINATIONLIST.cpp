// Think carefully >>>>>> Are you ready ??!!!!!!!!

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define ll long long
using namespace std;
//==================<< END OF TEMPLATE >>========================
int m,n,k,a[10050],Free[10050],cnt;
bool nosol;

//--------------<<ENF OF VARIABLES DECLARATION >>-----------------
void answer()
{
    for (int i=1;i<=m;i++) printf("%d ",a[i]);
    nosol=0;
}
void Try(int i)
{
    for (int j=a[i-1]+1;j<=n-(m-i);j++) if (Free[j])
    {
        a[i]=j; Free[j]=0;
        if (i<m) Try(i+1);
        else
        {
            cnt++;
            if (cnt==k)
            {
                answer();
                return ;
            }
        }
        Free[j]=1;
    }
}
int main()
{
    freopen("","r",stdin);
    freopen("","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) Free[i]=1;
    cnt=0; nosol=1;
    Try(1);
    if (nosol) printf("-1");
    return 0;
}

// Accepted in one hit, or be a silly dog :))
/* -----BACKUP -------------

*/
