#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "stock"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 250;
int a[N][N];
int n, t, res;
void update(int u, int v) {
    FOR(i, 1, n) FOR(j, 1, n)
    if (a[i][u] && a[v][j])
        a[i][j] = 1;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &t);
    FOR(i, 1, n) a[i][i] = 1;
    REP(z, t) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (a[v][u]) res ++;
        else if (!a[u][v]) update(u, v);
    }
    printf("%d", res);
}
