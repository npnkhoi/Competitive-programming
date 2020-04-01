#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define foru(i,a,b) for (int i=a;i<=b;i++)
#define ford(i,a,b) for (int i=a;i>=b;i--)
ll n,s;
ll res=0;
using namespace std;
ll sumdigit(ll a)
{
    ll s=0;
    while (a) s+=a%10, a/=10;
    return s;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> n >> s;
    if (n>=s+192) res=n-(s+192)+1;
    //cout << res << endl;
    for (ll a=s;a<=min(s+191,n);a++)
    if (a-sumdigit(a) >= s) res++;
    cout << res;
    return 0;
}
/* --------------------------<< BACK UP >>-------------------------

*/
