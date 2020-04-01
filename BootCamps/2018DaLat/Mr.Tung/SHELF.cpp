using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 1e5 + 5;
int n, q;
ll ft[N];

void update(int i, int v) {
    for (; i <= n; i += i&-i) ft[i] += v;
}
ll rsq(int i) {
    if (i < 1) return 0;
    ll res = 0;
    for (; i; i -= i&-i) res += ft[i];
    return res;
}
ll rsq(int l, int r) {
    return rsq(r) - rsq(l-1);
}
int main() {
    freopen("SHELF.inp", "r", stdin);
    freopen("SHELF.out", "w", stdout);
    int num, t;
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &num);
        update(i, num);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &t);
        printf("%lld\n", min(rsq(1, t-1), rsq(t+1, n)));
        update(t, 1);
    }
    return 0;
}
/** Happy Coding ^^ */

