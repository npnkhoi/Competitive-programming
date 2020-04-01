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
int n, m, t, p[N];

ll ans(int num) {
    ll res = 0;
    FOR(i, 1, n) res += num/p[i];
    return res;
}
int main() {
    freopen("LAVENDER.inp", "r", stdin);
    freopen("LAVENDER.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &t);
    FOR(i, 1, n) scanf("%d", &p[i]);
    ll res = t/m*ans(m) + ans(t%m);
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding ^^ */

