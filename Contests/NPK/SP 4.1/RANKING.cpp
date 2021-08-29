#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;
const int N = 1e6 + 20;
int m,n,b[N],f[N],mark[N];
int x,last,res;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    scanf("%d",&m);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    for (int i=1;i<=1e6+10;i++) mark[i]=i;

    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        int cnt = 0, i = mark[x];
        while (cnt<x && i<1e6+5)
        {
            f[i]=1;
            i+=x;
            mark[x]=i;
        }
    }
    res = 0;
    while (m--) res+= f[b[m+1]];
    cout << res;
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/

