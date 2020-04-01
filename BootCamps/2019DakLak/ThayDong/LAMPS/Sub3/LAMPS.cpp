#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "LAMPS"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105;
int tc, n;
int color[N], a[N][N], b[N][N], saveRow[N], x[N];
vi ans;

void show() {
    FOR(i, 1, n) {
        FOR(j, 0, n) cerr << b[i][j] << " ";
        cerr << "\n";
    }
    cerr << "\n";
}
void sub3() {
    FOR(i, 1, n) FOR(j, 1, n) b[i][j] = a[i][j];
    //show();
    FOR(k, 1, n) {
        int save;
        FOR(i, k, n) if (b[i][k] == 1) {
            save = i;
            break;
        }
        //cerr << save << "\n";
        FOR(j, 0, n) swap(b[save][j], b[k][j]);
        FOR(i, 1, n) if (i != k && b[i][k]) {
            FOR(j, 0, n) b[i][j] ^= b[k][j];
        }
        //show();
    }
    FOR(i, 1, n) if (b[i][0]) ans.pb(i);
    printf("%d", ans.size());
    REP(j, ans.size()) printf(" %d", ans[j]);
    printf("\n");
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &tc);
    FOR(i, 1, n) a[i][i] = 1;
    FOR(z, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    while (tc --) {
        FOR(i, 1, n)
            scanf("%d", &color[i]),
            b[i][0] = 1 - color[i];
        sub3();
    }
}
