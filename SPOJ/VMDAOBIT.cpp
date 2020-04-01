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
int a[N][N];
vector<ii> ans;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);

    for (int i = 1; i <= m-2; ++i)
    for (int j = 1; j <= n-2; ++j) if (a[i][j]) {
        for (int x = i; x <= i+2 && x <= m; ++x)
        for (int y = j; y <= j+2 && y <= n; ++y)
        a[x][y] = a[x][y] ^ 1;

        ans.push_back(mp(i, j));
    }
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) if (a[i][j]) {
        printf("-1");
        return 0;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].fi, ans[i].se);
    return 0;
}
/** Happy Coding ^^ */

