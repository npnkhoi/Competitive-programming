#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "number"
const int N = 1e3 + 5;
char a[N], b[N];
ii dp[N][N];
int m, n;
bool flag = 0;
void trace(int i, int j) {
    if (dp[i][j].fi == 0) return;
    ii tmp;
        tmp.fi = dp[i-1][j-1].fi + 1;
        tmp.se = a[i] - '0';
    if (a[i] == b[j]) {

        if (a[i] == b[j] tmp > dp[i-1][j] && tmp > dp[i][j-1]) {
            if (flag || a[i] != '0') {
                printf("%c", a[i]);
                flag = 1;
            }
        }
        trace(i-1, j-1);
    } else if (dp[i-1][j] > dp[i][j-1])
        trace(i-1, j);
    else trace(i, j-1);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%s", a+1);
    scanf("%s", b+1);
    m = strlen(a+1);
    n = strlen(b+1);
    FOR(i, 1, m) FOR(j, 1, n) {
        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        if (a[i] == b[j])
            dp[i][j] = max(dp[i][j], mp(dp[i-1][j-1].fi + 1, a[i] - '0'));
    }
    //cerr << dp[m][n].fi << "\n";
    trace(m, n);
}
/** Happy Coding :D */
