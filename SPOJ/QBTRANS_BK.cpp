//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
//typedef pair<int, int> ii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "test"
const int N = 105;
const long long oo = 1e18 + 7;
int n, m, cur, pre;
long long a[N][N], b[2][N][N];
double res;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    cur = 1; pre = 0; res = oo;
    FOR(i, 1, n) FOR(j, 1, n) a[i][j] = oo;
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long c;
        scanf("%d %d %lld", &u, &v, &c);
        a[u][v] = min(a[u][v], c);
    }
    FOR(i, 1, n) FOR(j, 1, n) b[cur][i][j] = a[i][j];

    FOR(numEdge, 2, n) {
        swap(cur, pre);
        FOR(i, 1, n) FOR(j, 1, n) {
                b[cur][i][j] = oo;
                FOR(k, 1, n) b[cur][i][j] = min(b[cur][i][j], b[pre][i][k] + a[k][j]);
            }
        FOR(i, 1, n) if (b[cur][i][i] < oo)
        res = min(res, (double) b[cur][i][i] / numEdge);
    }
    if (res == oo) printf("-1");
    else printf("%.3f", res);
}
/// Expelliarmus !
