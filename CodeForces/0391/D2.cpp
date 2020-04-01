#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "391D2"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 5e4 + 5;
const int MAX_FT = 15e4 + 5;
struct Line {
    int x, y, r;
};
struct Pack{
    int type;
    int x, y;
};
Pack makePack(int x, int type, int y) {
    Pack tmp;
    tmp.x = x;
    tmp.type = type;
    tmp.y = y;
    return tmp;
}
vi data;
Line ver[N], hor[N];
map<int, int> newVal;
Pack v[2*N];
int n, m, ft[3*N];
void update(int idx, int val) {
    //cerr << "update " << idx << " " << val << "\n";
    for (; idx <= MAX_FT; idx += idx & -idx) ft[idx] += val;
}
int get(int idx) {
    int res = 0;
    for (; idx; idx -= idx & -idx) res += ft[idx];
    return res;
}
int get(int l, int r) {
    if (l == 0) return r;
    else return get(r) - get(l-1);
}
bool ok(int k) {
    //cerr << "check " << k << "\n";
    data.clear();
    FOR(i, 1, n) if (ver[i].r >= 2*k) data.pb(ver[i].y + k), data.pb(ver[i].y + ver[i].r - k);
    FOR(i, 1, m) if (hor[i].r >= 2*k) data.pb(hor[i].y);
    sort(data.begin(), data.end());
    newVal.clear();
    int rr = 0;
    REP(i, data.size()) if (i == 0 || data[i] != data[i-1]) newVal[data[i]] = ++rr;

    int p = 0;
    FOR(i, 1, m) if (hor[i].r >= 2*k) {
        Pack tmp;
        v[++p] = makePack(hor[i].x + k, 1, newVal[hor[i].y]);
        v[++p] = makePack(hor[i].x + hor[i].r - k + 1, -1, newVal[hor[i].y]);
    }
    sort(v+1, v+p+1, [](Pack a, Pack b){
        if (a.x != b.x) return a.x < b.x;
        else return a.type > b.type;
    });
    //cerr << "minhkhuenghiusi\n";
    int cur = 1;
    memset(ft, 0, sizeof ft);
    FOR(i, 1, n) if (ver[i].r >= 2*k) {
        while (cur <= p && v[cur].x <= ver[i].x) update(v[cur].y, v[cur].type), cur ++;
        if (get(newVal[ver[i].y + k], newVal[ver[i].y + ver[i].r - k]) > 0) return 1;
    }
    return 0;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d%d%d", &ver[i].x, &ver[i].y, &ver[i].r);
    FOR(i, 1, m) scanf("%d%d%d", &hor[i].x, &hor[i].y, &hor[i].r);
    sort(ver+1, ver+n+1, [](Line a, Line b){
        return a.x < b.x;
    });
    int l = 0, r = 1e9, res = l;
    while (l <= r) {
        //cerr << l << " " << r << "\n";
        int mid = (l + r) / 2;
        if (ok(mid)) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", res);
}
