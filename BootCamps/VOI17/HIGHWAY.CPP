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
    bool operator <= (P &b) {
        if (x != b.x) return x < b.x;
        else return y <= b.y;
    }
    bool operator < (P &b) {
        if (x != b.x) return x < b.x;
        else return y < b.y;
    }
};
const int N = 7e5 + 5;

int ma, mb, na, nb;
ii ea[N], eb[N];
P va[N], vb[N];

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
bool inter(P a, P b, P c, P d) {
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
void show(P &a) {
    cerr << a.x << " " << a.y << "\n";
}
bool ok(int x, int y) {
    FOR(i, 1, ma) {
        //cerr << i << "\n";
        int u = ea[i].fi;
        int v = ea[i].se;
        if (u == x) {
            if (onSeg(va[x], vb[y], va[v]))
            return 0;
        }
        else if (v == x) {
            if (onSeg(va[x], vb[y], va[u]))
            return 0;
        }
        else if (inter(va[x], vb[y], va[u], va[v]))
            return 0;
    }
    FOR(i, 1, mb) {
        //cerr << i << "\n";
        int u = eb[i].fi;
        int v = eb[i].se;
        /*cerr << va[x].x << " " << va[x].y << " ";
        cerr << vb[y].x << " " << vb[y].y << " ";
        cerr << vb[u].x << " " << vb[u].y << " ";
        cerr << vb[v].x << " " << vb[v].y << " ";
        cerr << "\n";*/

        if (u == y) {
            if (onSeg(va[x], vb[y], vb[v]))
            return 0;
        }
        else if (v == y) {
            if (onSeg(va[x], vb[y], vb[u]))
            return 0;
        }
        else if (inter(va[x], vb[y], vb[u], vb[v]))
            return 0;
    }
    return 1;
}
int main() {
    freopen("HIGHWAY.inp", "r", stdin);
    freopen("HIGHWAY.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &na, &ma);
        FOR(i, 1, na) scanf("%lld%lld", &va[i].x, &va[i].y);
        FOR(i, 1, ma) scanf("%d%d", &ea[i].fi, &ea[i].se);
        scanf("%d%d", &nb, &mb);
        FOR(i, 1, nb) scanf("%lld%lld", &vb[i].x, &vb[i].y);
        FOR(i, 1, mb) scanf("%d%d", &eb[i].fi, &eb[i].se);

        bool cont = 1;
        for (int i = 1; i <= na && cont; ++i)
        for (int j = 1; j <= nb && cont; ++j)
            if (ok(i, j)) {
                printf("%d %d\n", i, j);
                cont = 0;
            }
        if (cont) printf("0\n");
        //cout << ok(1, 1) << "\n";
        //cout << inter(va[1], vb[1], vb[2], vb[4]);
    }
    /*show(va[51]); show(vb[47]);
    show(va[3]); show(va[437]);*/
    return 0;
}
/** Happy Coding :D */
