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
int a[1005];
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    int tc, n, k;
    scanf("%d", &tc);
    FOR(z, 1, tc) {
        scanf("%d%d", &n, &k);
        FOR(i, 1, n) scanf("%d", &a[i]);
        ll res = 0;
        while (1) {
            sort(a+1, a+n+1);
            if (a[n-k+1] <= 0) break;
            else {
                res += a[n-k+1];
                FOR(i, n-k+2, n) a[i] -= a[n-k+1];
                a[n-k+1] = 0;
            }
        }
        printf("Case %d: %lld\n", z, res);
    }
    return 0;
}
/** Happy Coding ^^ */

