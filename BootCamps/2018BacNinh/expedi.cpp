#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define task "expedi"

const int N = 1e4 + 5;
int n, cur, pre, dp[3][N];
ii a[N];
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    n ++;
    FOR(i, 1, n) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a+1, a+n+1);
    cur = 0, pre = 1;
    FOR(i, 1, n) {
        swap(pre, cur);
        dp[cur][0] = a[i].fi;
        FOR(j, 1, n)
            dp[cur][j] = max(0, a[i].fi - a[i-1].fi + min(dp[pre][j], dp[pre][j-1] - a[i].se));
        //FOR(j, 0, n) cerr << dp[cur][j] << " ";
        //cerr << "\n";
    }
    FOR(j, 0, n) if (dp[cur][j] == 0) {
        printf("%d", j - 1);
        return 0;
    }
    printf("-1");
    return 0;
}
/** Happy Coding :D */
