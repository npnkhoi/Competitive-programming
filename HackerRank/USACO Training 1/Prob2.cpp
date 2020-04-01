using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e3 + 5;
int n, m;
ii f[N], b[N];
int dp[N][N];
int dist(int i, int j) {
    return (f[i].fi - b[j].fi) * (f[i].fi - b[j].fi)
    + (f[i].se - b[j].se) * (f[i].se - b[j].se);
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%d %d", &f[0].fi, &f[0].se);
    scanf("%d %d", &b[0].fi, &b[0].se);
    char ch;
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &ch);
        f[i] = f[i-1];
        if (ch == 'N') f[i].se ++;
        else if (ch == 'S') f[i].se --;
        else if (ch == 'E') f[i].fi ++;
        else f[i].fi --;
    }
    for (int i = 1; i <= m; i++) {
        scanf(" %c", &ch);
        b[i] = b[i-1];
        if (ch == 'N') b[i].se ++;
        else if (ch == 'S') b[i].se --;
        else if (ch == 'E') b[i].fi ++;
        else b[i].fi --;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = dist(i, 0) + dp[i-1][0];
    for (int j = 1; j <= m; j++) dp[0][j] = dist(0, j) + dp[0][j-1];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    dp[i][j] = dist(i, j) + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
    printf("%d", dp[n][m]);

    return 0;
}
/** Happy Coding ^^ */

