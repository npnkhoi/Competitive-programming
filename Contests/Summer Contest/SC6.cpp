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
const int V = 5e4 + 5;
const int maxV = 5e4;
const ll oo = 1e18 + 7;
ll f[N][V];
int v[N], w[N];
int n, m;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(j, 1, maxV) f[0][j] = oo;
    REP(khue, tc) {
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) scanf("%d", &v[i]);
        FOR(i, 1, n) scanf("%d", &w[i]);
        FOR(i, 1, n) FOR(j, 1, maxV) {
            f[i][j] = f[i-1][j];
            if (j >= v[i]) f[i][j] = min(f[i-1][j], f[i-1][j-v[i]] + w[i]);
        }
        FORD(j, maxV, 0) if (f[n][j] <= m) {
            printf("%d\n", j);
            break;
        }
    }
}
