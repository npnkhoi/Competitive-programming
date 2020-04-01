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
const int M = 25;
const int N = 5e4 + 5;
int m, n, q, x;
int a[M][N], cnt[M];
void sub1() {
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    while (q--) {
        scanf("%d", &x);
        if (x <= m) ++ cnt[x];
        else {
            x -= m;
            for (int i = 1; i <= m; i++) ++ a[i][x];
        }
    }
    int res = 0;
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) res += (cnt[i] + a[i][j]) % 3 == 0;
    cout << res;
}
void sub2() {
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[j][i]);
    while (q--) {
        scanf("%d", &x);
        if (x <= m) {
            for (int j = 1; j <= n; j++) ++ a[j][x];
        } else ++ cnt[x-m];
    }
    int res = 0;
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) res += (cnt[j] + a[j][i]) % 3 == 0;
    cout << res;
}
int main() {
    freopen("LISYS.inp", "r", stdin);
    freopen("LISYS.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &q);
    if (m <= 20) sub1();
    else sub2();
    return 0;
}
/** Happy Coding ^^ */

