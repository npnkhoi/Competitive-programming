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
const int N = 103;
const int oo = 1e9 + 7;
vector<int> a, b, c;
int dp[2][N][N][N];

int get(int p, int i, int j, int k) {
    if (i > p || j > p || k > p) return -oo;
    return dp[p%2][i][j][k];
}
int main() {
    freopen("GAME.inp", "r", stdin);
    //freopen("GAME.out", "w", stdout);
    int n;
    scanf("%d", &n);
    a.push_back(0);
    b.push_back(0);
    c.push_back(0);

    int num;
    REP(i, n) {
        scanf("%d", &num);
        if (num) a.push_back(num);
    }
    REP(i, n) {
        scanf("%d", &num);
        if (num) b.push_back(num);
    }
    REP(i, n) {
        scanf("%d", &num);
        if (num) c.push_back(num);
    }
    int x = a.size() - 1;
    int y = b.size() - 1;
    int z = c.size() - 1;
    //printf("%d %d %d\n", x, y, z);

    FOR(p, 1, n)
    FOR(i, 1, min(p, x))
    FOR(j, 1, min(p, y))
    FOR(k, 1, min(p, z)) {
        int t = p % 2;
        dp[t][i][j][k] = -oo;
        dp[t][i][j][k] = max(dp[t][i][j][k], a[i] * b[j] * c[k] + get(p-1, i-1, j-1, k-1));

        dp[t][i][j][k] = max(dp[t][i][j][k], get(p-1, i-1, j-1, k));
        dp[t][i][j][k] = max(dp[t][i][j][k], get(p-1, i-1, j, k-1));
        dp[t][i][j][k] = max(dp[t][i][j][k], get(p-1, i, j-1, k-1));

        dp[t][i][j][k] = max(dp[t][i][j][k], get(p-1, i-1, j, k));
        dp[t][i][j][k] = max(dp[t][i][j][k], get(p-1, i, j-1, k));
        dp[t][i][j][k] = max(dp[t][i][j][k], get(p-1, i, j, k-1));
        //printf("dp[%d][%d][%d][%d] = %d\n", p, i, j, k, dp[t][i][j][k]);
    }
    cout << dp[n%2][x][y][z] << endl;
    //cout << dp[1][1][1][1];
    return 0;
}
/** Happy Coding ^^ */

