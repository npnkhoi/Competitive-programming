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

const int N = 1e5 + 5;
const ll oo = 1e18 + 8;
int n, x[N], y[N], tmp[N];
ll res;

void calc() {
    ll s = 0;
    int med;

    med = x[(n+1)/2];
    FOR(i, 1, n) s += abs(x[i] - med);

    FOR(i, 1, n) tmp[i] = y[i] - i;
    sort(tmp + 1, tmp + n + 1);
    med = tmp[(n+1)/2];
    FOR(i, 1, n) s += abs(tmp[i] - med);

    res = min(res, s);
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &x[i], &y[i]);
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    res = oo;
    calc();
    FOR(i, 1, n) swap(x[i], y[i]);
    calc();
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding :D */
