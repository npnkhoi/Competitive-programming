#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "E"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

ll n;
ll memo[(int)3e7 + 5], fac[20];
bool flag = 0;
int idx[15], base[15];

ll dp() {
    //REP(i, 10) cerr << idx[i] << " "; cerr << "\n";
    int id = 0;
    REP(i, 10) id += idx[i] * base[i];

    if (memo[id] != -1) return 0;

    int tmp = 0;
    REP(i, 10) tmp += idx[i];

    memo[id] = fac[tmp];
    REP(i, 10) memo[id] /= fac[idx[i]];

    REP(i, 10) if (idx[i] > 1 || (i == 0 && flag && idx[0] == 1)) {
        idx[i] --;
        memo[id] += dp();
        idx[i] ++;
    }
    //cerr << memo[id] << "\n";
    return memo[id];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);

    fac[0] = 1;
    FOR(i, 1, 19) fac[i] = fac[i-1] * i;


    cin >> n;
    ll m = n;

    while (m > 0) {
        idx[m % 10] ++;
        m /= 10;
    }
    base[9] = 1;
    FORD(i, 8, 0) base[i] = max(idx[i+1], 1) * base[i+1];
    //REP(i, 10) cerr << base[i] << " "; cerr << "\n";

    memset(memo, -1, sizeof memo);
    ll res = dp();
    if (idx[0] > 0) {
        //cerr << "here\n";
        memset(memo, -1, sizeof memo);
        flag = 1;
        idx[0] --;
        res -= dp();
    }
    cout << res;
}
