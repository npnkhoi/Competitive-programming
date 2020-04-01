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

#define task "ps"
int n, val;
long long sum;
vector<li> v;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &val);
        sum += val;
        v.pb(mp(sum, i));
    }
    v.pb(mp(0, 0));
    sort(v.begin(), v.end());
    //REP(i, v.size()) cerr << v[i].fi << " " << v[i].se << "\n";

    int minpos = n, save = n, res = 0, lo, hi;

    REP(i, v.size()) {
        save = min(save, v[i].se);
        if (i == v.size() - 1 || v[i].fi != v[i+1].fi) {
            if (v[i].se - minpos > res) {
                res = v[i].se - minpos;
                hi = v[i].se;
            }
            minpos = min(minpos, save);
        }
    }
    printf("%d %d", hi - res + 1, hi);
}
/** Happy Coding :D */
