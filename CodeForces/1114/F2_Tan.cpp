#include<bits/stdc++.h>
using namespace std;
 
#define y1 as214
#define ii pair < ll , ll >
#define iii pair < ll , ii >
#define iv pair < ii , ii >
 
#define fi first
#define se second
#define fr front()
#define t top()
#define pb push_back
 
#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
 
#define ll long long
#define oo 999999999
#define Nga cute
 
const int N = 1e5 + 5;
map < ii , ll > m;
ll n , a[N] , res , s;
 
int main()
{
    //freopen("1.inp","r",stdin);
    cin >> n;
    FOR(i , 1 , n)
        cin >> a[i];
    FOR(i , 1 , n)
    {
        s = 0;
        for(ll j = i ; j >= 1 ; j--)
        {
            s += a[j];
            m[ii(i , s)] = max(m[ii(i , s)] , m[ii(j - 1 , s)] + 1);
            m[ii(i + 1 , s)] = m[ii(i , s)];
            res = max(res ,  m[ii(i , s)]);
            cerr << j << ' ' << i << ' ' << s << ' ' << m[ii(i, s)] << '\n';
        }
    }
    cout << res;
}