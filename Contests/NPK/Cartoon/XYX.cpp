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
#define taskName ""

const int N = 3e4 + 5;
string cal[N], rec[N];
int n, t[N];
vector<string> v;
map<string, int> id;
ll positive[2*N];

int toSec(int x) {
    int tmp, res = 0;
    res += x % 100;
    x /= 100;
    res += x % 100 * 60;
    x /= 100;
    res += x * 3600;
    return res;
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int beginTime, endTime;
    FOR(i, 1, n) {
        cin >> cal[i] >> rec[i] >> beginTime >> endTime;
        v.pb(cal[i]);
        v.pb(rec[i]);
        t[i] = toSec(endTime) - toSec(beginTime);
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    REP(i, 2*n) if (i == 0 || v[i] != v[i-1])
        id[v[i]] = ++ cnt;
    FOR(i, 1, n) {
        positive[id[cal[i]]] += 2 * t[i];
        positive[id[rec[i]]] += t[i];
    }
    ll res = 0;
    FOR(i, 1, cnt) res = max(res, positive[i]);
    cout << res;

    return 0;
}
/** Happy Coding :D */
