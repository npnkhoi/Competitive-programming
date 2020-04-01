#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "ladder"
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
struct pack{
    int l, r, h, ord;
};

const int N = 2e5 + 5;
const long long oo = 1e18;
int n, H, p;
pack a[N];
int idL[N], idR[N];
int IT[4*N], lazy[8*N];
long long dist[N];
priority_queue<li, vector<li>, greater<li> > heap;
vector<ii> adj[N];
vector<int> v;
map<int, int> id;

bool cmp(pack a, pack b) {
    return (a.h < b.h || (a.h == b.h && a.l < b.l));
}
void lazyDown(int p) {
    if (lazy[p] != -1) {
        IT[p] = lazy[p];
        lazy[2*p] = lazy[2*p+1] = lazy[p];
        lazy[p] = -1;
    }
}
void show(int p, int l, int r) {
    printf("node(%d, %d, %d): %d\n", p, l, r, IT[p]);
}
void update(int p, int l, int r, int L, int R, int val) {
    if (l > r || L > R || l > R || L > r) return;
    //printf("update %d %d\n", l, r);
    lazyDown(p);
    if (L <= l && r <= R) {
        IT[p] = val;
        lazy[2*p] = lazy[2*p+1] = val;
    } else {
        int mi = (l+r)/2;
        update(2*p, l, mi, L, R, val);
        update(2*p+1, mi+1, r, L, R, val);
    }
}
int query(int idx) {
    int node = 1, l = 1, r = p;
    while (l < r) {
        lazyDown(node);
        int mi = (l+r)/2;
        if (idx <= mi) {
            node = 2 * node;
            r = mi;
        } else {
            node = 2 * node + 1;
            l = mi + 1;
        }
    }
    lazyDown(node); return IT[node];

    /*if (idx < l || r < idx) return -1;
    lazyDown(p);
    if (l == idx && idx == r) return IT[p];
    else {
        int mi = (l+r) / 2;
        if (idx <= mi) return query(2*p, l, mi, idx);
        else return query(2*p, mi+1, r, idx);
    }*/
}
long long dijsktra(int s, int t) {
    FOR(i, 0, 2*n) dist[i] = oo; dist[s] = 0;
    heap.push(mp(0, s));
    while (!heap.empty()) {
        ll d = heap.top().fi;
        int u = heap.top().se;
        heap.pop();
        if (d > dist[u]) continue;

        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist[v.fi] > d + v.se) {
                dist[v.fi] = d + v.se;
                heap.push(mp(dist[v.fi], v.fi));
            }
        }
    }
    return dist[t];
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &H);
    FOR(i, 1, n) {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].h);
        a[i].ord = i;
        v.pb(a[i].l);
        v.pb(a[i].r);
    }
    sort(a+1, a+n+1, cmp);

        sort(v.begin(), v.end());
        p = 0;
        REP(i, v.size()) if (i == 0 || (v[i] != v[i-1]))
            id[v[i]] = ++ p;
        FOR(i, 1, n) idL[i] = id[a[i].l], idR[i] = id[a[i].r];

    //FOR(i, 1, n) printf("%d %d %d %d\n", a[i].l, a[i].r, a[i].h, a[i].ord);
    //cerr << "ok\n";
    memset(lazy, -1, sizeof lazy);
    FOR(i, 1, n) {
        int u = 2 * a[i].ord - 1, v = 2 * a[i].ord;
        adj[u].pb(mp(v, a[i].r - a[i].l));
        adj[v].pb(mp(u, a[i].r - a[i].l));

        int tmp;
        tmp = query(idL[i]);
        //cerr << tmp << '\n';
        if (a[i].h - a[tmp].h <= H)
        if (tmp) {
            adj[u].pb(mp(2 * a[tmp].ord - 1, a[i].h - a[tmp].h + abs(a[i].l - a[tmp].l)));
            adj[u].pb(mp(2 * a[tmp].ord, a[i].h - a[tmp].h + abs(a[i].l - a[tmp].r)));
        } else adj[u].pb(mp(0, a[i].h - a[tmp].h));

        tmp = query(idR[i]);
        //cerr << tmp << '\n';
        if (a[i].h - a[tmp].h <= H)
        if (tmp) {
            adj[v].pb(mp(2 * a[tmp].ord - 1, a[i].h - a[tmp].h + abs(a[i].r - a[tmp].l)));
            adj[v].pb(mp(2 * a[tmp].ord, a[i].h - a[tmp].h + abs(a[i].r - a[tmp].r)));
        } else adj[v].pb(mp(0, a[i].h - a[tmp].h));
        //cerr << "update\n";
        update(1, 1, p, idL[i], idR[i], i);
        //cerr << idL[i] << " " << idR[i] << "\n";
        //FOR(j, 1, p) cerr << query(j) << " "; cerr << "\n";
        //printf("update %d %d\n", idL[i], idR[i]);
        //cerr << "end update\n";
    }
    /*FOR(i, 0, 2*n) {
        printf("%d:\n", i);
        REP(j, adj[i].size()) cerr << adj[i][j].fi << " " << adj[i][j].se << "\n";
    }*/
    printf("%lld", dijsktra(1, 0));
}
/// Expelliarmus !
