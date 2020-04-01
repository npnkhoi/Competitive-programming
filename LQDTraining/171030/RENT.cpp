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
const int N = 500 + 5;
int a[N][N];
int sum(int x, int y, int u, int v) {
    return a[u][v] - a[u][y-1] - a[x-1][v] + a[x-1][y-1];
}
int main() {
    freopen("RENT.inp", "r", stdin);
    freopen("RENT.out", "w", stdout);
    int m, n, x, y;
    scanf("%d%d%d%d", &m, &n, &x, &y);
    y += x;
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1] - y;
    }
    int res = 0;
    int res1, res2, res3, res4;
    for (int u = 1; u <= n; ++u)
    for (int v = u; v <= n; ++v) {
        int s = 0, pos = 1;
        for (int i = 1; i <= m; ++i) {
            if (s <= 0) {
                s = 0;
                pos = i;
            }
            s += sum(i, u, i, v);
            if (res < s) {
                res = s;
                res1 = pos;
                res2 = u;
                res3 = i;
                res4 = v;
            } else if
            (res == s && (res3-res1+1) * (res4-res2+1) > (i-pos+1)*(v-u+1)) {
                res1 = pos;
                res2 = u;
                res3 = i;
                res4 = v;
            }
        }
    }
    if (res == 0) printf("0");
    else printf("%d %d %d %d %d", res, res1, res2, res3, res4);
    return 0;
}
/** Happy Coding ^^ */

