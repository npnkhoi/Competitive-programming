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

const int N = 1e5 + 5;
const long long oo = 1e18 + 7;
int n, a[N];
long long m, f[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d %lld", &n, &m);
    FOR(i, 1, n) {
        f[i] = oo;
        scanf("%d", &a[i]);
        if (a[i] > m) {
            printf("-1");
            exit(0);
        }
        int curMax = 0;
        long long curSum = 0;
        FORD(j, i, 1) {
            curSum += a[j];
            if (curSum > m) break;
            curMax = max(curMax, a[j]);
            f[i] = min(f[i], f[j-1] + curMax);
        }
    }
    printf("%lld", f[n]);
}
/// Expelliarmus !
