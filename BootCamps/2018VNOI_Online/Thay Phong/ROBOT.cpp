#include <cstdio>
#include <cstring>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)
#define task "robot"
using namespace std;
//typedef pair<int, int> ii;
typedef long long ll;
const int N = 1e5 + 5;
char s[N];
int k, n, a[N];
long long res;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &k);
    scanf("%s", s+1);
    n = strlen(s+1);

    FOR(i, k+1, n) a[i] = a[i-1] + (s[i] == s[i-k]);

    FOR(i, k, n-1) {
        int l, r, mi, d;
        l = i, r = n, d = i;

        while (l <= r) {
            mi = (l+r)/2;
            if (a[mi] - a[i] == mi - i) {
                d = max(d, mi);
                l = mi + 1;
            } else r = mi - 1;
        }
        res += d - i;
    }
    printf("%lld", res);
}
