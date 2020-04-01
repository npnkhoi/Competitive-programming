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
const int N = 400 + 5;
const int oo = 1e9 + 7;
int a[N][N];
int n, m, res;
int sum(int x, int y, int u, int v) {
    return a[u][v] - a[u][y-1] - a[x-1][v] + a[x-1][y-1];
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
    res = -oo;
    for (int u = 1; u < n; u++)
    for (int v = u+1; v <= n; v++) {
        int tmp = sum(1, u+1, 1, v-1);
        for (int i = 2; i <= m; i++) {
            int x = sum(i, u, i, v) + sum(1, u, i-1, u) + sum(1, v, i-1, v);
            int y = sum(i, u+1, i, v-1) - sum(1, u, i-1, u) - sum(1, v, i-1, v);
            res = max(res, x + tmp);
            tmp = max(tmp, y);
        }
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding ^^ */

