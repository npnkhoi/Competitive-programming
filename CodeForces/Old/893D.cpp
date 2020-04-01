using namespace std;
#include <bits/stdc++.h>
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
const int N = 1e5 + 5;
int a[N], maxInc[N];
int n, d;

int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    maxInc[n+1] = 0;
    FORD(i, n, 1) maxInc[i] = max(0, a[i] + max(0, maxInc[i+1]));
    ll cur = 0;
    int res = 0;
    FOR(i, 1, n) if (a[i] != 0) {
        cur += a[i];
        if (cur > d) {
            printf("-1");
            exit(0);
        }
    } else {
        if (cur < 0) {
            //printf("day %d %d\n", i, cur);
            res ++;
            cur = d - maxInc[i+1];
            //cerr << cur << "\n";
            if (cur < 0) {
                printf("-1");
                exit(0);
            }
        }
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding :D */

