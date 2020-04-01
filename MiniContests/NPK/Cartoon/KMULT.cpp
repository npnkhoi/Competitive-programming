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
#define taskName ""

const int N = 1e5 + 5;
const int K = 100 + 5;
int n, k, a[N];
bool dp[N][K];

int mod(int x) {
    if (x < 0) return x + k;
    else if (x >= k) return x - k;
    else return x;
}
void trace(int i, int j) {
    if (i > 1) {
        if (dp[i-1][mod(j + a[i])]) {
            trace(i-1, mod(j + a[i]));
            printf("-");
        } else {
            trace(i-1, mod(j - a[i]));
            printf("+");
        }
    }
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        a[i] %= k;
        if (a[i] < 0) a[i] += k;
    }
    dp[1][a[1]] = 1;
    FOR(i, 2, n) FOR(j, 0, k-1)
        dp[i][j] = dp[i-1][mod(j + a[i])] | dp[i-1][mod(j - a[i])];
    if (dp[n][0]) {
        printf("1\n");
        trace(n, 0);
    } else printf("0\n");
    return 0;
}
/** Happy Coding :D */
