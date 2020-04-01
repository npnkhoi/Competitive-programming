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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 3e4 + 5;
typedef pair<ii, int> pack;
pack t[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;
int main() {
    freopen("WISCHEDULE.inp", "r", stdin);
    freopen("WISCHEDULE.out", "w", stdout);
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d", &t[i].fi.fi, &t[i].fi.se, &t[i].se);
    sort(t, t+n);
    pq.push(mp(0, 0));
    int tmp = 0, res = 0;
    REP(i, n) {
        while (!pq.empty() && pq.top().fi <= t[i].fi.fi) {
            tmp = max(tmp, pq.top().se);
            pq.pop();
        }
        res = max(res, tmp + t[i].se);
        pq.push(mp(t[i].fi.se, tmp + t[i].se));
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
