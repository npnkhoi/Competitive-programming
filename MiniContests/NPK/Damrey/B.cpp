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
const int N = 1e5 + 5;
const int M = 12;
bool dp[M][N];
char a[M][N];
vector<ii> ans;
int n;

void push(int x) {
    //printf("push %d\n", x);
    if (ans.empty() || ans.back().fi != x+1) ans.push_back(mp(x, 1));
    else {
        int tmp = ans.back().se;
        ans.pop_back();
        ans.push_back(mp(x, tmp+1));
    }
}
void trace(int i, int j) {
    //printf("trace %d %d\n", i, j);
    if (j == 0) return;

    if (i == 0) {
        if (dp[1][j-1]) {
            push(j-1);
            trace(1, j-1);
        } else {
            push(j-1);
            trace(0, j-1);
        }
    } else if (i == 9) {
        if (dp[9][j-1]) {
            trace(9, j-1);
        } else
            trace(8, j-1);
    } else {
        if (dp[i+1][j-1]) {
            push(j-1);
            trace(i+1, j-1);
        }
        else trace(i-1, j-1);
    }
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("B.inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d", &n);
    REP(i, 10) REP(j, n) scanf(" %c", &a[i][j]);
    dp[9][0] = 1;
    FOR(j, 1, n-1) {
        FOR(i, 1, 8) if (a[i][j] == '.')
            dp[i][j] = dp[i-1][j-1] | dp[i+1][j-1];
        if (a[0][j] == '.') dp[0][j] = dp[0][j-1] | dp[1][j-1];
        if (a[9][j] == '.') dp[9][j] = dp[8][j-1] | dp[9][j-1];
    }
    REP(i, 10) if (dp[i][n-1]) {
        trace(i, n-1);
        break;
    }
    /*REP(i, 10) {
        REP(j, n) cout << a[i][j];
        cout << "\n";
    }
    cout << "\n";
    REP(i, 10) {
        REP(j, n) cout << dp[i][j];
        cout << "\n";
    }*/
    printf("%d\n", ans.size());
    FORD(i, ans.size() - 1, 0) printf("%d %d\n", ans[i].fi, ans[i].se);
    return 0;
}
/** Happy Coding :D */
