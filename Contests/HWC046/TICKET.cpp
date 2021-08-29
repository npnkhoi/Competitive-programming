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

const int N = 105;
const int oo = 1e9 + 7;
int n, m;
int dp[N][N];
bool busy[N];

int main() {
    freopen("TICKET.inp", "r", stdin);
    freopen("TICKET.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int num;
    FOR(i, 1, m) {
        scanf("%d", &num);
        busy[num] = 1;
    }
    FOD(i, n, 1) FOR(j, 0, n) {
        int res = oo;
        if (i+1 <= n+1) {
            res = min(res, dp[i+1][j] + 10000);
            if (j >= 3)
            res = min(res, dp[i+1][j-3]);
        }
        if (i+3 <= n+1) res = min(res, dp[i+3][j+1] + 25000);
        if (i+5 <= n+1) res = min(res, dp[i+5][j+2] + 37000);

        if (i+1 <= n+1 && busy[i]) res = min(res, dp[i+1][j]);

        dp[i][j] = res;
    }
    /*FOR(i, 1, n) {
        FOR(j, 0, n) printf("%7d", dp[i][j]);
        cout << endl;
    }*/
    printf("%d", dp[1][0]);
    return 0;
}
/** Happy Coding ^^ */

