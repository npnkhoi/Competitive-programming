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
const int N = 1e3 + 5;
struct pack {
    int x, y, r;
};
pack a[N], b[N];
int n, m, res;
int calc(pack a, pack b) {
    return min(min(b.x + b.r - a.x, a.x - b.x), min(a.y + a.r - b.y, b.y - a.y));
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);
    FOR(i, 1, m) scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].r);
    //show(a[5]);
    //show(b[4]);
    FOR(i, 1, n) FOR(j, 1, m) {
        res = max(res, calc(a[i], b[j]));
        //cerr << i << " " << j << " " << res << "\n";
    }
    printf("%d", res);
}
