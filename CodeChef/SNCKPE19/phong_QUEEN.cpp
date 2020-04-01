#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = a ;i <= b ; ++i)
#define ROF(i,a,b) for (int i = a ;i >= b ; --i)
#define REP(i,a) for (int i = 0 ; i < a ; i++)
#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define pb push_back
#define pu push

const int HashMod=1190490533;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;

int T, n, m, x, y;

void Init(){


    return ;
}

void Inp(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen("Test.inp","r",stdin);
    //freopen("Test.out","w",stdout);
    return ;
}

ll Calc(int n, int m, int x, int y){
    ll mi = min(n, m);
    ll all_pos = ( (nm) * (n*m-1) ) ;
    ll all_queen = (n + m - 2) * (n * m)
                 + 2 * ( ( mi - 1) * mi * (abs(m - n) + 1) + ( (mi - 2) * (mi-1) * (mi) * 2  ) / 3 ) + (n * m);
    ll hi_queen =  x * (n - x) + (n - x + 1) * (x - 1)
                 + y * (m - y) + (m - y + 1) * (y - 1)
                 + (min(x,y) * min(n-x, m-y) + (min(n-x,m-y) + 1) * (min(x,y) - 1))
                 + (min(n-x+1, y)) * (min(x-1, m-y)) + (min(x-1, m-y) + 1) * (min(n-x+1, y) - 1)
                 + (x-1) + (y-1) + (n-x) + (n-y) + min(x,y)-1 + min(n-x, m-y) + min(n-x, y-1) + min(x-1,m-y);

    cout << all_pos - all_queen + hi_queen  << "\n";

    return 0;
}
void Process(){

    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("Test.inp","r",stdin);
    //freopen("Test.out","w",stdout);
    cin >> T;
    while (T--){
        cin >> n >> m >> x >> y;
        cout << Calc(n, m, x, y) << "\n";
    }
    return 0;
}