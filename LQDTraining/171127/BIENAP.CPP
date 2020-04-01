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

#define taskName "BIENAP"

const int N = 305;
const int P = 35;
const int oo = 1e9 + 7;
int n, p;
int x[N], s[N], dp[N][P];

int sum(int l, int r) {
    return s[r] - s[l-1];
}
int cost(int l, int r) {
    int med = (l+r+1)/2;
    return (x[med] * (med - l) - sum(l, med - 1)) + (sum(med+1, r) - x[med] * (r - med));
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &p);
    FOR(i, 1, n) scanf("%d", &x[i]);
    sort(x+1, x+n+1);
    FOR(i, 1, n) s[i] = x[i] + s[i-1];

    FOR(i, 1, n) dp[i][0] = oo;
    FOR(i, 1, n) FOR(j, 1, p) {
        dp[i][j] = oo;
        FOR(k, 0, i - 1) dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost(k+1, i));
    }
    /*FOR(i, 1, n) {
        FOR(j, 1, p) printf("%5d", dp[i][j]);
        cerr << "\n";
    }*/

    printf("%d", dp[n][p]);

    return 0;
}
/** Happy Coding :D */
