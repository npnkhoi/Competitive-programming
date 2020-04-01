
// THINHK CAREFULLY ... ARE YOU READY !?

//#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)
const int md=1e6;
using namespace std;
//==================<< END OF TEMPLATE >>========================
int n,k,s;
int f[110][110];
//--------------<< ENF OF VARIABLES DECLARATION >>---------------

//-------------------<< END OF FUNCTIONS >>---------------------
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    while (1)
    {
        scanf("%d%d",&n,&k);
        if (!n||!k) break;
        for (int i=1;i<=n;i++) f[i][0]=0;
        f[0][0]=1;
        for (int i=0;i<=n;i++)
        for (int j=1;j<=k;j++)
        {
            s=0;
            for (int x=0;x<=i;x++) s=(s+f[x][j-1])%md;
            f[i][j]=s;
        }
        printf("%d\n",f[n][k]);
    }
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
