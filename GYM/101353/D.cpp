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

int cnt[100005];

int main() {
    freopen("", "r", stdin);
    freopen("", "w", stdout);
    int tc, n, num;
    scanf("%d", &tc);
    FOR(z, 1, tc) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        while (n--) {
            scanf("%d", &num);
            ++ cnt[num];
        }
        printf("Case %d: ", z);

        int sl = 0, save = 0;
        bool done = 0;
        FOR(i, 1, 1e5) {
            sl += cnt[i] % 2;
            if (cnt[i]%2) save = cnt[i];
            if (sl >= 3) {
                printf("0\n");
                done = 1;
                break;
            }
        }
        if (done == 0) {
            if (sl == 0) printf("0\n");
            else printf("%d\n", save);
        }
    }
    return 0;
}
/** Happy Coding ^^ */

