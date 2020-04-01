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
const int N = 2e5 + 5;
int n, k;
ii a[N];
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    freopen("POWER.inp", "r", stdin);
    freopen("POWER.out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a+1, a+n+1, greater<ii>());
    FOR(i, 1, k) pq.push(a[i].se);
    ll res = 1LL * a[k].fi * pq.top();
    FOR(i, k+1, n) {
        pq.pop();
        pq.push(a[i].se);
        res = max(res, 1LL * a[i].fi * pq.top());
    }
    cout << res;
    return 0;
}
/** Happy Coding ^^ */

