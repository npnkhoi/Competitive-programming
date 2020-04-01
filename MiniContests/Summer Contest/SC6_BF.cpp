#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "SC6"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105;
const int M = 5e4 + 5;
const int maxM = 5e4;
const int oo = 1e9 + 7;
int f[N][M];
int v[N], w[N];
int n, m;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(j, 1, maxM) f[0][j] = -oo;
    REP(khue, tc) {
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) scanf("%d", &v[i]);
        FOR(i, 1, n) scanf("%d", &w[i]);
        FOR(i, 1, n) FOR(j, 1, m) {
            f[i][j] = f[i-1][j];
            if (j >= w[i]) f[i][j] =
                max(f[i][j], f[i-1][j-w[i]] + v[i]);
            //cerr << i << " " << j << " " << f[i][j] << "\n";
            //cerr << "back to " << i-1 << " " << j - w[i] << "\n";
        }

        int res = 0;
        FOR(j, 0, m) res = max(res, f[n][j]);
        printf("%d\n", res);
    }
}
