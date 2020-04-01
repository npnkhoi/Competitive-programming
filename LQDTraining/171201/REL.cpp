using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
struct P {
    ll x, y;
};

const int N = 1e5 + 5;

P a[N], b[N];
int m, n, p1, p2;
bool mark[N];
ll sqr(ll x) {return x*x;}
ll dist(P &a, P &b) { /// square of distance
    return sqr(b.x - a.x) + sqr(b.y - a.y);
}
ll ccw(P &a, P &b, P &c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
double shadow(P &a, P &b, P &c) {
    ll tx = (a.x - b.x) * (c.x - b.x);
    ll ty = (a.y - b.y) * (c.y - b.y);
    return (double) (tx + ty) / sqrt(1.0*dist(b, c));
}
double Cos(P &a, P &b, P &c) {
    ll tx = (a.x - b.x) * (c.x - b.x);
    ll ty = (a.y - b.y) * (c.y - b.y);
    //cerr << tx << " " << ty << "\n";
    //if (tx + ty < 0) return -1;

    return (double) (tx + ty) / sqrt(dist(b, c)) / sqrt(dist(b, a));
}
bool inTriangle(P &m, P &a, P &b, P &c) {
    return ccw(a, m, b) <= 0 &&
    ccw(b, m, c) <= 0 && ccw(c, m, a) <= 0;
}
int pre(int x) {
    if (x == 1) return m;
    else return x - 1;
}
int nex(int x) {
    if (x == m) return 1;
    else return x + 1;
}
int pos1(int p, int td) {
    int x =  pre(td);
    int y = td;
    int z = nex(td);
    //printf("%d %d %d\n", x, y, z);
    ll s1 = ccw(a[p], b[y], b[x]);
    ll s2 = ccw(a[p], b[y], b[z]);
    //cerr << s1 << " " << s2 << "\n";

    if (s1 >= 0 && s2 > 0) return 3;
    else if (s1 <= 0 && s2 <= 0) return 1;
    else if (s1 >= 0) return 2;
    else return 4;
}
int pos2(int p, int td) {
    int x =  pre(td);
    int y = td;
    int z = nex(td);
    ll s1 = ccw(a[p], b[y], b[x]);
    ll s2 = ccw(a[p], b[y], b[z]);

    if (s1 < 0 && s2 <= 0) return 1;
    else if (s1 >= 0 && s2 >= 0) return 3;
    else if (s1 >= 0) return 2;
    else return 4;
}
void update1(int &r, int &td, int p) { /// old root, tiep diem, candidate
    //printf("update1 %d %d %d\n", r, td, p);
    int tmp = pos1(p, td);
    //cerr << tmp << "\n";
    if (tmp == 3) {
        if (ccw(a[r], b[td], a[p]) <= 0) r = p;
    } else if (tmp != 4) {
        r = p;
        do td = nex(td);
        while (ccw(a[p], b[td], b[nex(td)]) <= 0);
    }
}
void update2(int &r, int &td, int p) { /// old root, tiep diem, candidate
    int tmp = pos2(p, td);
    if (tmp == 1) {
        if (ccw(a[r], b[td], a[p]) >= 0) r = p;
    } else if (tmp != 4) {
        r = p;
        do td = pre(td);
        while (ccw(a[p], b[td], b[pre(td)]) >= 0);
    }
}
void hurry(int r) {
    int p1 = 1, p2 = 1;
    FOR(i, 2, m) {
        if (ccw(a[r], b[p1], b[i]) < 0) p1 = i;
        if (ccw(a[r], b[p2], b[i]) > 0) p2 = i;
    }
    FOR(i, 2, n)
        if (ccw(a[r], b[p1], a[i]) <= 0 || ccw(a[r], b[p2], a[i]) >= 0 ||
        inTriangle(a[i], a[r], b[p1], b[p2])) {
            //if (mark[i] == 0) cerr << r << "!\n";
            mark[i] = 1;
        }
}

int main() {
    freopen("REL.inp", "r", stdin);
    freopen("REL.out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld%lld", &a[i].x, &a[i].y);
    scanf("%d", &m);
    FOR(i, 1, m) scanf("%lld%lld", &b[i].x, &b[i].y);

    p1 = 1, p2 = 1; /// tiep tuyen phai va trai
    FOR(i, 2, m) {
        if (ccw(a[1], b[p1], b[i]) < 0) p1 = i;
        if (ccw(a[1], b[p2], b[i]) > 0) p2 = i;
    }
    while (ccw(a[1], b[p1], b[nex(p1)]) == 0) p1 = nex(p1);
    while (ccw(a[1], b[p2], b[pre(p2)]) == 0) p2 = pre(p2);
    //cerr << p1 << " " << p2 << "\n";

    int r1 = 1, r2 = 1;
    int td1 = p1, td2 = p2; /// td: tiep diem

    FOR(i, 2, n) {
        if (ccw(a[1], b[p1], a[i]) <= 0) {
            mark[i] = 1;
            update1(r1, td1, i);
        }
        if (ccw(a[1], b[p2], a[i]) >= 0) {
            mark[i] = 1;
            update2(r2, td2, i);
        }
        if (inTriangle(a[i], a[1], b[p1], b[p2])) mark[i] = 1;
        //cerr << r1 << " " << r2 << "\n";
    }
    //cerr << r1 << " " << r2 << "\n";
    //update1(r1, td1, 4);
    //r2 = 276;

    /*vector<int> tmp;
    FOR(i, 2, n) if (mark[i]) tmp.push_back(i);
    hurry(r1); hurry(r2);

    REP(i, tmp.size()) hurry(tmp[i]);*/
    hurry(r1); hurry(r2);

    int res = 0;
    FOR(i, 2, n) res += mark[i];
    printf("%d\n", res);
    return 0;
}
