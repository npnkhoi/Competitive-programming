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

const int HashMod=1125022017;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int oo = 2e9;
const int MOD = 1e9 + 7 ;
vector <int> Prime;
vector <ll> big_Prime;
int min_Prime[1000009];
int x[83000];
int x_size;
int b, n;
ll dp[13001][1001];
void Build_Prime(){
    int cnt = 0 ;
    for (int i = 2 ; i * i <= 1e6 ; i ++ ){
        if (!min_Prime[i] && ( i % 2 !=0 || i == 2)) {
            for (ll j = i * i ; j <= 1e6 ; j += i)
                if (!min_Prime[j] && j % 2 !=0)
                    min_Prime[j] = cnt;
            ++ cnt;
        }
    }
    Prime.pb(2);
    min_Prime[2] = 0;
    FOR(i, 2, 1e6)
        if (!min_Prime[i] && i % 2 != 0)
            Prime.pb(i), min_Prime[i] = Prime.size()-1;
    return ;
}

void Calc(ll val){

    REP(i, Prime.size()){
        while (val % Prime[i] == 0){
            val /= Prime[i];
            ++ x[i];
        }
        if (val < 1e6)
            break;
    }
    // //cerr <<  "ok" << val << "\n";
    if (val > 1e6){
        big_Prime.pb(val);
    }
    else{
        while (val > 1){
            // //cerr << "\n";
            // //cerr << Prime[min_Prime[val]] <<"\n";
            ++ x[min_Prime[val]];
            val /= Prime[min_Prime[val]];
        }
    }
    return ;
}

void Build_big_Prime(){
    x_size = Prime.size()-1;
    sort(big_Prime.begin(), big_Prime.end());
    int cnt = 0;
    REP(i, big_Prime.size()){
        ++ cnt;
        if (i+1 == big_Prime.size() || big_Prime[i] != big_Prime[i+1]){
            x[++x_size] = cnt;
            cnt = 0;
        }
    }
    return ;
}
void Inp(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen("Test.inp","r",stdin);
    //freopen("Test.out","w",stdout);
    cin >> b >> n;
    FOR(i, 1, n){
        ll val;
        cin >> val;
        Calc(val);
    }
    return ;
}

bool comp(int x, int y){
    return x > y ;
}
void Process(){
    sort(x, x + x_size, comp);
    FOR(i, 0, x_size){
        if (x[i] == 0){
            x_size = i - 1;
            break;
        }
    }
    FOR(i, 1, x[0]+1)
        dp[0][i] = 1;
    FOR(i, 1, x_size)
        FOR(j, 1, b){
            dp[i][j] = 0;
            FOR(k, 1, sqrt(j))
                if (j % k == 0){
                    if (k <= x[i] + 1)
                        dp[i][j] = (dp[i][j] + dp[i-1][j/k]) % MOD;
                    if (k * k != j && j/k <= x[i] + 1)
                        dp[i][j] = (dp[i][j] + dp[i-1][k] ) % MOD;
                }
        }
    cout << dp[x_size][b];
    //cerr << "================\n";

    return ;
}

int main(){
    Build_Prime();
    Inp();
    Build_big_Prime();
    Process();
    return 0;
}