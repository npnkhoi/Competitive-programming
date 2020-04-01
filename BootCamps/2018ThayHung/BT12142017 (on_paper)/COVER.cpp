#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "cover"

const int N = 1e5 + 5;
pair<ii, int> s[N];
int n, a, b;
vi ans;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &a, &b);
    FOR(i, 1, n) {
        scanf("%d%d", &s[i].fi.fi, &s[i].fi.se);
        s[i].se = i;
    }
    sort(s+1, s+n+1);
    int cur = a, nex = a, p = 1, save;
    while (1) {
        if (cur >= b) break;
        while (p <= n && s[p].fi.fi <= cur) {
            if (s[p].fi.se > nex) {
                nex = s[p].fi.se;
                save = s[p].se;
            }
            p ++;
        }
        if (nex <= cur) {
            printf("-1");
            exit(0);
        }
        cur = nex;
        ans.pb(save);
        //cerr << save << " " << nex << "\n";
    }
    printf("%d\n", (int)ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);

}
/** Happy Coding :D */
