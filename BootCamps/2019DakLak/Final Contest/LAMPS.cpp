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

const int N = 3e3 + 5;
int a[N][N], b[N][N], color[N];
int n, tc;
vi ans;

void show() {
    FOR(i, 1, n) {
        FOR(j, 0, n) cerr << b[i][j] << " ";
        cerr << "\n";
    }
    cerr << "\n";
}
void gaussElim() {
    //show();
    FOR(k, 1, n) {
        int save = -1;
        FOR(i, k, n) if (b[i][k]) {
            save = i;
            break;
        }
        if (save == -1) continue;
        if (save != k) FOR(j, 0, n) swap(b[k][j], b[save][j]);
        FOR(i, 1, n) if (i != k && b[i][k]) {
            FOR(j, 0, n) b[i][j] ^= b[k][j];
        }
        //show();
    }
    ans.clear();
    FOR(i, 1, n) if (b[i][i]) {
        if (b[i][0]) ans.pb(i);
    } else if (b[i][0] == 1) {
        printf("-1\n");
        return;
    }
    printf("%d", ans.size());
    REP(i, ans.size()) printf(" %d", ans[i]);
    printf("\n");
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &tc);
    FOR(i, 1, n) a[i][i] = 1;
    REP(z, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    REP(khue, tc) {
        FOR(i, 1, n) {
            scanf("%d", &color[i]);
            b[i][0] = color[i] ^ 1;
            FOR(j, 1, n) b[i][j] = a[i][j];
        }
        if (n <= 1000) gaussElim();
        else printf("-1\n");
    }
}
