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

const int N = 105;
const int maxH = 110;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int a[N][N], n;
bool mark[N][N];

bool ok(int h1, int h2) {
    if (a[1][1] < h1 || a[1][1] > h2) return 0;
    memset(mark, 0, sizeof mark); mark[1][1] = 1;
    queue<ii> q; q.push(mp(1, 1));
    while (!q.empty()) {
        ii tmp = q.front(); q.pop();
        REP(z, 4) {
            int u = tmp.fi + di[z];
            int v = tmp.se + dj[z];
            if (1 <= u && u <= n && 1 <= v && v <= n &&
            !mark[u][v] && h1 <= a[u][v] && a[u][v] <= h2) {
                if (u == n && v == n) return 1;
                mark[u][v] = 1;
                q.push(mp(u, v));
            }
        }
    }
    return 0;
}
int minDiff(int val) {
    int l = val, r = maxH, x = r;
    while (l <= r) {
        int mi = (l+r)/2;
        if (ok(val, mi)) {
            x = min(x, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    if (ok(val, x)) return x - val;
    else return maxH;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d", &n);
    if (n == 1) {
        printf("0");
        exit(0);
    }
    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
    int res = maxH;
    FOR(i, 0, a[1][1]) res = min(res, minDiff(i));
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
