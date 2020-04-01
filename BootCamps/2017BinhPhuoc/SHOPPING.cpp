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

#define taskName ""
const int N = 3e5 + 5;
int n, m, a[N], IT[4*N];
void build(int p, int l, int r) {
    if (l == r) IT[p] = a[l];
    else {
        int mi = (l+r)/2;
        build(2*p, l, mi);
        build(2*p+1, mi+1, r);
        IT[p] = min(IT[2*p], IT[2*p+1]);
    }
}
int rmq(int p, int l, int r, int u, int v) {
    if (u > r || l > v || u > v) return -1;
    else if (u <= l && r <= v) return IT[p];
    else {
        int mi = (l+r)/2;
        int v1 = rmq(2*p, l, mi, u, v);
        int v2 = rmq(2*p+1, mi+1, r, u, v);
        if (v1 == -1) return v2;
        else if (v2 == -1) return v1;
        else return min(v1, v2);
    }
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        ll t;
        int l, r;
        scanf("%lld%d%d", &t, &l, &r);
        int tmp = rmq(1, 1, n, l, r);
        printf("%lld\n", t % tmp);
    }
    return 0;
}
/** Happy Coding :D */
