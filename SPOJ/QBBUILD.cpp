#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) FOR(j, 1, n)
        if (i != j) c[i][j] = oo;
    FOR(i, 1, 4) scanf("%d", &a[i]);
    while (scanf("%d%d%d", &u, &v, &w)) {
        a[u][v] = min(a[u][v], w);
        a[v][u] = min(a[v][u], w);
    }

}
