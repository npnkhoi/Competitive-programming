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

#define taskName "0"

const int N = 1e5 + 5;
const int K = 23;
int n, k;
bool dp[N][K][K];

bool palin(int a) {
    int tmp = a, b = 0;
    while (tmp > 0) {
        b = 10 * b + tmp % 10;
        tmp /= 10;
    }
    return a == b;
}
bool lucky(int a) {
    if (a < 10) return a == 4 || a == 7;
    else return (a % 10 == 4 || a % 10 == 7) && lucky(a/10);
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &k);
    dp[0][k][k] = 1;
    FOR(i, 1, n) {
        int val;
        scanf("%d", &val);
        bool a1 = palin(val), a2 = lucky(val);
        //cerr << a1 << " " << a2 << "\n";
        if ((a1 || a2) == 0) {
            printf("No\n");
            exit(0);
        }
        if (a1)
            FOR(x, 0, k) FOR(y, 1, k) {
                int yy;
                if (y == k) yy = k; else yy = y - 1;
                if (x == k) dp[i][x][y] |= dp[i-1][k-1][yy];
                else dp[i][x][y] |= dp[i-1][k][yy] | dp[i-1][k-1][yy];
            }
        if (a2)
            FOR(x, 1, k) FOR(y, 0, k) {
                int xx;
                if (x == k) xx = k; else xx = x - 1;
                if (y == k) dp[i][x][y] |= dp[i-1][xx][k-1];
                else dp[i][x][y] |= dp[i-1][xx][k] | dp[i-1][xx][k-1];
            }
        /*FOR(x, 0, k) FOR(y, 0, k) {
            printf("dp(%d, %d, %d) = ", i, x, y);
            cerr << dp[i][x][y] << "\n";
        }*/
    }
    if (dp[n][k][k]) printf("Yes\n");
    else printf("No\n");
    return 0;
}
/** Happy Coding :D */
