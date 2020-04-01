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
struct P {
    ll x, y;
    bool operator <= (P &a) {
        if (x != a.x) return x < a.x;
        else return y <= a.y;
    }
    bool operator < (P &a) {
        if (x != a.x) return x < a.x;
        else return y < a.y;
    }
};
const int N = 2000 + 5;
vector<P> v[N];
vector<int> adj[N];
bitset<N> vis;
int n, res, cnt;
int ccw(P &a, P &b, P &c) {
    ll tmp = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
    if (tmp == 0) return 0;
    else if (tmp > 0) return 1;
    else return -1;
}
bool inRec(P &a, P &b, P &c) {
    return (c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) &&
            c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y));
}
bool onSeg(P &a, P &b, P &c) {
    return ccw(a, b, c) == 0 && inRec(a, b, c);
}
bool inter(P &a, P &b, P &c, P &d) {
    int p1 = ccw(a, b, c);
    int p2 = ccw(a, b, d);
    int p3 = ccw(c, d, a);
    int p4 = ccw(c, d, b);
    //printf("%d %d %d %d\n", p1, p2, p3, p4);

    if (p1*p2 < 0 && p3*p4 < 0) return 1;

    if (p1 == 0 && inRec(a, b, c)) return 1;
    if (p2 == 0 && inRec(a, b, d)) return 1;
    if (p3 == 0 && inRec(c, d, a)) return 1;
    if (p4 == 0 && inRec(c, d, b)) return 1;

    return 0;
}
int inc(int x, int n) {
    if (x+1 < n) return x+1;
    else return x+1-n;
}
bool inter(vector<P> &a, vector<P> &b) {
    int m = a.size(), n = b.size();
    REP(i, m) REP(j, n)
        if (inter(a[i], a[inc(i, m)], b[j], b[inc(j, n)]))
            return 1;
    return 0;
}
void dfs(int u) {
    vis[u] = 1; ++ cnt;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (vis[v] == 0) dfs(v);
    }
}
int main() {
    freopen("RECT.inp", "r", stdin);
    freopen("RECT.out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        v[i].resize(4);
        REP(j, 4) scanf("%lld%lld", &v[i][j].x, &v[i][j].y);
    }
    FOR(i, 1, n-1) FOR(j, i+1, n) {
        if (inter(v[i], v[j])) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    FOR(i, 1, n) if (vis[i] == 0) {
        cnt = 0;
        dfs(i);
        res = max(res, cnt); // global cnt
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */

