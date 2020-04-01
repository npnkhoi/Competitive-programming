#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define task "cinema"
const int N = 1e5 + 5;
const ll oo = 1e18 + 7;
int a[N], b[N], c[N];
ll dp[N][5];
int n;

bool biton(int mask, int i) {
    return (mask & (1 << i)) > 0;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    dp[0][1] = dp[0][2] = dp[0][3] = -oo;
    FOR(i, 1, n) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        FOR(mask, 0, 3) {
            dp[i][mask] = dp[i-1][mask] + a[i];
            if (biton(mask, 0)) dp[i][mask] = max(dp[i][mask], dp[i-1][mask^1] + b[i]);
            if (biton(mask, 1)) dp[i][mask] = max(dp[i][mask], dp[i-1][mask^2] + c[i]);
            //printf("dp(%d, %d) = %lld\n", i, mask, dp[i][mask]);
        }
    }
    printf("%lld\n", dp[n][3]);
}
