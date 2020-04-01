#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define taskName "POPUST"

const int N = 5e5 + 5;
const int oo = 2e9 + 7;

ii p[N];
int minA[N];

int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    ifstream fin(taskName".inp");
    ofstream fou(taskName".out");
    int n;
    //scanf("%d", &n);
    //FOR(i, 1, n) scanf("%d%d", &p[i].se, &p[i].fi); /// fi: b[i], se: a[i]
    fin >> n;
    FOR(i, 1, n) fin >> p[i].se >> p[i].fi;
    sort(p+1, p+n+1);

    /// minA[i]: min reserved cost (i -> n)
    minA[n+1] = oo;
    FORD(i, n, 1) minA[i] = min(minA[i+1], p[i].se);

    int minDiff = oo;
    ll s = 0;

    FOR(i, 1, n) {
        ll tmp = minA[i] + s;

        s += p[i].fi;
        minDiff = min(minDiff, p[i].se - p[i].fi);

        //printf("%lld\n", min(tmp, s + minDiff));
        fou << min(tmp, s + minDiff) << "\n";
    }
    return 0;
}
/** Happy Coding :D */
