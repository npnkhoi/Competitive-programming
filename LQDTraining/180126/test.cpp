#include <cstdio>
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,n) for (int i = a; i >= b; i--)
#define task "test"
typedef pair<long long, long long> pll;
const int base1 = 26;
const int base2 = 37;
const long long md = 1e9 + 7;
const int N = 2e5 + 5;
int n;
string s;
pll v[N];
//queue<pll> q;
pll h[N], POW[N];

void hashInit() {
    POW[0] = mp(1, 1);
    FOR(i, 1, N - 1) {
        POW[i].fi = POW[i-1].fi * base1 % md;
        POW[i].se = POW[i-1].se * base2 % md;
    }
}
void hashBuild(string &s, pll h[]) {
    h[0] = mp(s[0] % md, s[0] % md);
    FOR(i, 1, s.size() - 1) {
        h[i].fi = (h[i-1].fi * base1 + s[i]) % md;
        h[i].se = (h[i-1].se * base2 + s[i]) % md;
    }
}
inline pll hashGet(pll h[], int l, int r) {
    if (l == 0) return h[r];
    pll res;
    res.fi = (h[r].fi - h[l-1].fi * POW[r-l+1].fi + md * md) % md;
    res.se = (h[r].se - h[l-1].se * POW[r-l+1].se + md * md) % md;
    return res;
}
bool ok(int val) {
    int m = n - val + 1;
    for (int i = 0; i + val - 1 < n; i++)
        v[i] = hashGet(h, i, i + val - 1);
    sort(v, v + m);
    FOR(i, 1, m - 1) if (v[i] == v[i-1]) return true;
    return false;
}
int main() {
    double Time = clock();
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d ", &n);
    getline(cin, s);
    hashInit();
    hashBuild(s, h);
    int l = 0, r = s.size() - 1, res = l;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (ok(mid)) {
            res = max(res, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d\n", res);
    Time = (clock() - Time) / CLOCKS_PER_SEC;
    cerr << Time;
}

