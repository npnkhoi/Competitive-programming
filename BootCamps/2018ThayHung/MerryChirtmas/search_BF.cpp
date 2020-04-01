#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "search"
typedef long long ll;
//typedef pair<int, int> ii;

const int N = 1e5 + 5;
int a[N], b[N], c[N];
int m, n, p, res;

bool appear(int val, int l, int r) {
    FOR(i, l, r) if (c[i] == val) return 1;
    return 0;
}
bool ok(int l, int r) {
    FOR(i, 1, m) if (!appear(a[i], l, r)) return 0;
    FOR(i, 1, n) if (appear(b[i], l, r)) return 0;
    return 1;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d %d %d", &m, &n, &p);
    FOR(i, 1, m) scanf("%d", &a[i]);
    FOR(i, 1, n) scanf("%d", &b[i]);
    FOR(i, 1, p) scanf("%d", &c[i]);
    FOR(l, 1, p) FOR(r, l, p) if (ok(l, r))
        res = max(res, r-l+1);
    printf("%d", res);
}
/// Expelliarmus !
