#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define fi first
#define se second
#define mp make_pair
#define pb psuh_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)
#define task "protest"
using namespace std;
//typedef pair<int, int> ii;
typedef long long ll;
const int md = 1e9 + 9;
const int N = 1e5 + 5;
int a[N], n, rr, f[N];
long long s[N], ft[N];
vector<long long> v;
map<long long, int> id;

void update(long long idx, int val) {
    for (; idx <= rr; idx += idx & -idx) ft[idx] = (ft[idx] + val) % md;
}
int get(long long idx) {
    int res = 0;
    for (; idx; idx -= idx & -idx) res = (res + ft[idx]) % md;
    return res;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    v.push_back(0);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        s[i] = a[i] + s[i-1];
        v.push_back(s[i]);
    }
        sort(v.begin(), v.end());
        REP(i, v.size())
            if (i == 0 || v[i] != v[i-1])
            id[v[i]] = ++ rr;
        FOR(i, 0, n) s[i] = id[s[i]];
    f[0] = 1;
    update(s[0], 1);
    FOR(i, 1, n) {
        f[i] = get(s[i]);
        update(s[i], f[i]);
    }
    printf("%d", f[n]);
}
