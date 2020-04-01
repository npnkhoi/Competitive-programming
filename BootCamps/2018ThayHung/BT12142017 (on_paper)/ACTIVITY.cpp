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

#define task "activity"

const int N = 1e6 + 5;
pair<ii, int> a[N];
int n, cur;
vector<int> ans;

bool cmp(pair<ii, int> a, pair<ii, int> b) {
    return a.fi.se < b.fi.se;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d%d", &a[i].fi.fi, &a[i].fi.se);
        a[i].se = i;
    }
    sort(a+1, a+n+1, cmp);
    cur = 0;
    FOR(i, 1, n) if (a[i].fi.fi >= cur) {
        cur = a[i].fi.se;
        ans.pb(a[i].se);
    }
    printf("%d\n",(int)ans.size());
    REP(i, ans.size()) printf("%d\n", ans[i]);
}
/** Happy Coding :D */
