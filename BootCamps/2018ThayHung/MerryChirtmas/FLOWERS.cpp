#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include  <algorithm>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "flowers"
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
ii a[N], v[N];
map<string, int> id;
string str;
int n, m, k, cnt[N];
int curL, curR, curCnt, res;

bool cmp(ii a, ii b) {
    int x = a.fi / m;
    int y = b.fi / m;
    if (x != y) return x < y;
    else return (a.se < b.se);
}
void update(int val, int delta) {
    cnt[val] += delta;
    if (delta > 0) curCnt += (cnt[val] == 1);
    else curCnt -= (cnt[val] == 0);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    m = (int) sqrt(n);
    FOR(i, 1, n) {
        scanf("%d ", &a[i].fi);
        getline(cin, str);
        if (id.find(str) == id.end())
            id[str] = (int) id.size();
        a[i].se = id[str];
    }
    sort(a+1, a+n+1);
    //FOR(i, 1, n) cerr << a[i].fi << " " << a[i].se << "\n";
    //cerr << "\n";
    int l = 1;
    FOR(r, 1, n) {
        while (a[r].fi - a[l].fi > k) l++;
        v[r] = mp(l, r);
        //cerr << l << " " << r << "\n";
    }
    sort(v + 1, v + n + 1, cmp);

    curL = 1;
    curR = 0;
    curCnt = 0;

    FOR(i, 1, n) {
        //cerr << v[i].fi << " " << v[i].se << "\n";
        if (curL < v[i].fi)
            FOR(j, curL, v[i].fi - 1) update(a[j].se, -1);
        else
            FOR(j, v[i].fi, curL - 1) update(a[j].se, +1);

        if (curR < v[i].se)
            FOR(j, curR + 1, v[i].se) update(a[j].se, +1);
        else
            FOR(j, v[i].se + 1, curR) update(a[j].se, -1);

        curL = v[i].fi; curR = v[i].se;
        //FOR(j, 0, 5) cerr << cnt[j] << " "; cerr << "\n";
        //cerr << curCnt << "\n";
        res = max(res, curCnt);
    }
    printf("%d", res);
}
/// Expelliarmus !
