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
int n;
vector<pair<int, ii> > v;
bool flag[N];
int t[N];
int main() {
    freopen("COVERING.inp", "r", stdin);
    freopen("COVERING.out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x, y, z;
        scanf("%d%d", &x, &y);
        v.push_back(mp(x, mp(0, i)));
        v.push_back(mp(y, mp(1, i)));
    }
    sort(v.begin(), v.end());
    int m = 0, res = 0;
    REP(i, v.size()) {
        //printf("%d %d %d\n", v[i].fi, v[i].se.fi, v[i].se.se);
        if (flag[v[i].se.se] == 0)
            if (v[i].se.fi == 1) {
                ++ res;
                flag[v[i].se.se] = 1;

                FOR(i, 1, m) flag[t[i]] = 1;
                m = 0;
            } else t[++m] = v[i].se.se;
        /*cerr << "--->";
        FOR(i, 1, m) cerr << t[i] << " ";
        cerr << endl;-*/
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding ^^ */

