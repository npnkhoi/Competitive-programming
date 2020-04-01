using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e5 + 5;
int n, l, r;
int m, res;
pair<ii, int> a[N];
vector<int> ans;
void sub0() {
    int u, v;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &u, &v);
        if (u <= l && l <= v) {
            printf("1\n%d\n", i);
            return;
        }
    }
    printf("-1");
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d %d", &n, &l, &r);
    if (l == r) {
        sub0();
        return 0;
    }
    int u, v;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &u, &v);
        if (v >= l) a[++m] = mp(mp(u, v), i);
    }
    sort(a + 1, a + m + 1);
    //for (int i = 1; i <= m; i++) printf("-> %d %d %d\n", a[i].fi.fi, a[i].fi.se, a[i].se);
    int cur = l, nex = l;
    int tmp;
    for (int i = 1; i <= m; i++) {
        if (a[i].fi.fi > cur) {
            if (nex <= cur) {
                printf("-1");
                return 0;
            } else {
                res ++;
                cur = nex;
                ans.push_back(tmp);
                if (cur >= r) break;
            }
        }
        if (a[i].fi.fi <= cur) {
            if (a[i].fi.se > nex) {
                nex = a[i].fi.se;
                tmp = a[i].se;
            }
        } else {
            printf("-1");
            return 0;
        }
    }
    if (cur < r) {
        if (nex >= r) {
            res ++;
            ans.push_back(tmp);
        } else {
            printf("-1");
            return 0;
        }
    }
    printf("%d\n", res);
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);

    return 0;
}
/** Happy Coding ^^ */

