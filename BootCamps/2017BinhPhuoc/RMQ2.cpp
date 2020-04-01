
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define taskName "RMQ2"
const int N = 505;
int a[N][N], IT[4*N][4*N];
int m, n, q, oo;
void build(int IT[], int a[], int p, int l, int r) {
    if (l == r) IT[p] = a[l];
    else {
        int mi = (l+r) >> 1;
        build(IT, a, p << 1, l, mi);
        build(IT, a, (p << 1) + 1, mi+1, r);
        IT[p] = min(IT[p << 1], IT[(p << 1) + 1]);
    }
}
void build2(int p, int l, int r) { /// n : num of col
    if (l == r) build(IT[p], a[l], 1, 1, n);
    else {
        int mi = (l+r) >> 1;
        build2(p << 1, l, mi);
        build2((p << 1) + 1, mi+1, r);
        FOR(i, 1, n << 2) IT[p][i] = min(IT[2*p][i], IT[2*p+1][i]);
    }
}
int rmq(int IT[], int p, int l, int r, int L, int R) {
    //printf("RMQ %d %d %d %d %d\n", p, l, r, L, R);
    if (L > R || l > r || L > r || l > R) return oo;
    else if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r) >> 1;
        int tmp1 = rmq(IT, p << 1, l, mi, L, R);
        int tmp2 = rmq(IT, (p << 1) + 1, mi+1, r, L, R);
        return min(tmp1, tmp2);
    }
}
int rmq2(int p, int l, int r, int x, int y, int u, int v) {
    //printf("RMQ2 %d %d %d %d %d %d %d %d\n", p, l, r, x, y, u, v, n);
    if (l > r || x > u || l > u || x > r) return oo;
    if (x <= l && r <= u) {
        //cerr << "return RMQ2\n";
        return rmq(IT[p], 1, 1, n, y, v);
    } else {
        int mi = (l+r) >> 1;
        int v1 = rmq2(p << 1, l, mi, x, y, u, v);
        int v2 = rmq2((p << 1) + 1, mi+1, r, x, y, u, v);
        return min(v1, v2);
    }
}
void showIT(int IT[], int p, int l, int r) {
    if (l == r) printf("(%d, %d) -> %d\n", l, r, IT[p]);
    else {
        printf("(%d, %d) -> %d\n", l, r, IT[p]);
        int mi = (l+r)/2;
        showIT(IT, 2*p, l, mi);
        showIT(IT, 2*p+1, mi+1, r);
    }
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) {
        scanf("%d", &a[i][j]);
        oo = max(oo, a[i][j]);
    }
    build2(1, 1, m);
    //showIT(IT[1], 1, 1, n);
    scanf("%d", &q);
    while (q--) {
        int x, y, u, v;
        scanf("%d%d%d%d", &x, &y, &u, &v);
        //printf("%d %d %d %d\n", x, y, u, v);
        printf("%d\n", rmq2(1, 1, m, x, y, u, v));
    }
    return 0;
}
/** Happy Coding :D */
