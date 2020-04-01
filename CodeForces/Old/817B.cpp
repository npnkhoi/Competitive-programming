#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)

using namespace std;
int n,a[100010];
ll x,y;
long long res;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    y=1;
    for (int i=4;i<=n;i++) if (a[i]==a[3]) y++; else break;
    x=1;
    for (int i=2;i>=1;i--) if (a[i]==a[3]) x++; else break;
    y+=x-1;
    if (x==1) res=y;
    else if (x==2) res=y*(y-1)/2;
    else res=1LL*y*(y-1)*(y-2)/6;
    cout << res;
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
