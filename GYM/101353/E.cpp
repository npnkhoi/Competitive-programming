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
int tc, n, num;
int cnt[N];
int main() {
    freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        //memset(cnt, 0, sizeof cnt);
        REP(i, n) {
            scanf("%d", &num);
            ++ cnt[num];
        }
        ll s1 = 0, s2 = 0;
        //ll tmp = 0;
        ll add = 0;
        FOR(i, 1, 1e5) if (cnt[i] > 0) {
            //++ tmp;
            s1 += cnt[i];
            s2 += 1LL * cnt[i] * cnt[i];
            if (cnt[i] > 1) add = 1;
            cnt[i] = 0;
        }
        printf("%lld\n", add + 1LL * (s1 * s1 - s2) / 2);
    }
    return 0;
}
/** Happy Coding ^^ */

