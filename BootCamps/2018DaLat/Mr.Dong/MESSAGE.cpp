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

void sub1() {
    FOR(i, 1, n) REP(j, 26) {
        REP(k, 26) dp[i][j] = (dp[i][j] + dp[i-1][j]) % md;
    }
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &n, &md);
        scanf("%s", s+1);
        if (n <= 100) sub1();
    }
    return 0;
}
/** Happy Coding ^^ */
