using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int A = 86;
ll fib[A+5], dp[A+5][3];
bool mark[A+5];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("sumfib.inp", "r", stdin);
    //freopen("sumfib.out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= A+1; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        //cerr << i << " " << fib[i] << "\n";
        //if (fib[i] >= 1e18) break;
    }
    int tc; ll num;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%lld", &num);
        //-------------------------
        FORD(i, A, 1)
        if (num >= fib[i]) {
            mark[i] = 1;
            num -= fib[i];
        } else mark[i] = 0;
        //-------------------------

        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = !mark[1];

        FOR(i, 2, A) {
            dp[i][0] = dp[i-1][1] + dp[i-1][0];

            if (mark[i] && i-2 >= 1) dp[i][1] = dp[i-2][2];
            else dp[i][1] = 0;

            if (mark[i]) {
                if (i-2 >= 1) dp[i][2] = dp[i-2][2];
                else dp[i][2] = 0;
            } else {
                dp[i][2] = dp[i-1][1] + dp[i-1][0];
                if (!mark[i-1]) dp[i][2] += dp[i-2][2];
            }
        }
        printf("%lld\n", dp[A][0] + dp[A][1]);
        /*cerr << "---\n";
        FOR(i, 1, 5) cerr << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
        cerr << "----\n";*/
    }
    //cerr << dp(86, 3) << "\n";
    return 0;
}
/** Happy Coding :D */
