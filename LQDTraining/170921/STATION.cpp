using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e4 + 10;
int l, n, cur, nex, i, res;
ii a[N];
int main() {
    freopen("station.inp", "r", stdin);
    freopen("station.out", "w", stdout);
    scanf("%d %d", &l, &n);
    REP(j, n) {
        int x, r;
        scanf("%d %d", &x, &r);
        a[j] = mp(x-r, x+r);
    }
    sort(a, a+n);
    cur = 0; nex = 0; i = 0;

    REP(i, n) {
        if (a[i].fi > cur) cur = nex, res ++;

        if (a[i].fi <= cur) nex = max(nex, a[i].se);
        else {
            printf("-1"); return 0;
        }
        //printf("%d %d %d\n", cur, nex, res);
    }
    if (cur < l) cur = nex, res ++;
    if (cur >= l) printf("%d", n - res);
    else printf("-1");
    return 0;
}
/** Happy Coding ^^ */
