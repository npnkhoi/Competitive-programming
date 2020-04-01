// Status: AC
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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 3005;
string s;
int memo[N][N], sum[N];
int total, n, m, res;
int nRed(int i, int j) {
    int s = sum[j];
    if (i) s -= sum[i-1];
    return total - s;
}
int dp(int i, int j) {
    if (j-i+1 == n) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    return memo[i][j] = max(
        int(s[j+1] == 'D') + nRed(i, j+1) - dp(i, j+1),
        int(s[i-1] == 'D') + nRed(i-1, j) - dp(i-1, j));
}
int main() {
    freopen("SELECT.inp", "r", stdin);
    freopen("SELECT.out", "w", stdout);
    memset(memo, -1, sizeof memo);
    getline(cin, s);
    n = s.size();

    s = s + s + s;
    m = 3*n;

    REP(i, m) {
        sum[i] = (s[i] == 'D');
        if (i) sum[i] += sum[i-1];
    }
    total = sum[n-1];

    FOR(i, n, 2*n-1) res += (2 * dp(i,i) < total);
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
