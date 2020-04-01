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
#define task "flowers"

const int N = 1e5 + 5;
ll t[N], d[N];
int id[N], n;
bool cmp(int i, int j) {
    return d[i] * t[j] > d[j] * t[i];
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%lld%lld", &t[i], &d[i]);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    ll sTime = 0,res = 0;
    FOR(i, 1, n) {
        //printf("%d: %lld %lld\n", id[i], d[id[i]], t[id[i]]);
        res += sTime * d[id[i]];
        sTime += 2LL * t[id[i]];
        //printf("%lld %lld\n", sTime, res);
    }
    printf("%lld", res);
    return 0;
}
/** Happy Coding :D */
