#include <cstdio>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "select"
typedef long long ll;
//typedef pair<int, int> ii;
const int N = 1e6 + 5;
const int sh = 1e6;
int n, a[N], cnt[2*N], curDiff;
long long res;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        char ch;
        scanf(" %c", &ch);
        if (ch == '+') a[i] = a[i-1] + 1;
        else a[i] = a[i-1] - 1;
    }
    cnt[sh] = 1;
    FOR(i, 1, n) {
        res += cnt[sh + a[i]];
        cnt[sh + a[i]] ++;
        if (i <= n-2) {
            int tmp = a[n] - a[i+1];
            res += cnt[sh - tmp];
            if (tmp == 0) res --;
        }

    }
    printf("%lld", res);
}
/// Expelliarmus !
