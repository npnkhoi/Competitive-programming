#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
void chmin(ll &a,ll b){a = min(a,b);}
ll inf = 1e18;

signed main(){
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    ll n;cin>>n;
    vector<ll> a(n+1),b(n+1);
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(2,inf)));
    dp[1][0][0] = a[1];
    dp[1][1][1] = 0;
    rep(i,2,n)rep(j,0,1)rep(k,0,1)rep(prej,0,1){
        chmin(dp[i][j][k],dp[i-1][prej][k] + (j==0?a[i]:0) + (j==prej?b[i-1]:0));
    }
    ll ans = inf;
    rep(j,0,1)rep(k,0,1)chmin(ans,dp[n][j][k] + (j==k?b[n]:0));
    cout<<ans<<endl;
    return 0;
}
