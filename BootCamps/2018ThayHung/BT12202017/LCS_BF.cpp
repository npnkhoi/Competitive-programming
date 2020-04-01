/* <3 <3 <3 */
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
#define debug(x) cerr << #x << " : " << x << "\n"

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;
const int nmax = 1e3 + 9;

vector <int> pos[(int)1e6 + 5];

int n,m;
int a[nmax];
int dp[nmax][nmax];

void Inp(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("LCS.inp","r",stdin);
    //freopen("LCS.ans","w",stdout);
    cin >> n >> m;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,m){
        int val;
        cin >> val;
        pos[val].pb(i);
    }
}

int NextPos(int index, int val){
    int res = upper_bound(pos[val].begin(), pos[val].end(), index) - pos[val].begin();
    if (res == pos[val].size())
        return m + 1;
    return pos[val][res];
}

void Trace (int i, int j){
    if (i == 0 || j == 0)
        return ;
    if (dp[i][j] == m + 1)
        Trace(i,j-1);
    else
        if (dp[i][j] == dp[i-1][j])
            Trace(i-1,j);
        else
            Trace(i-1,j-1), cout << a[i] << " ";
}
void Process(){
    //cerr << "ok\n";
    int ans = 0;
    FOR(i,0,n)
        FOR(j,1,n)
            dp[i][j] = m + 1;
    dp[0][0] = 0 ;
    FOR(j,1,n)
        FOR(i,1,n){
            dp[i][j] = min( dp[i-1][j], NextPos(dp[i-1][j-1], a[i]));
            if (dp[i][j] <= m)
                ans = max(ans, j);
        }
    cout << ans << "\n";
    Trace(n, n);
}

int main(){
    Inp();
    Process();
    return 0;
}
