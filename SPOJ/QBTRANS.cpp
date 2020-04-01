//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
//typedef pair<int, int> ii;
struct TEdge{
    int u, v, c;
};

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "qbtrans"
const int N = 105;
const int M = 9005;
const double EPS = 1e-4;
int n, m;
int a[N][N];
double d[N];
TEdge e[M];

bool relax(TEdge e, double delta) {
    if (d[e.u] + e.c - delta + EPS < d[e.v]) {
        //cerr << d[e.v] - (d[e.u] + e.c - delta) << "\n";
        //printf("relax True: %.20f %.20f\n", d[e.v], d[e.u] + e.c - delta);

        d[e.v] = d[e.u] + e.c - delta;

        return true;
    } return false;
}
bool ok(double delta) {
    FOR(i, 1, n) d[i] = 0;
    REP(loop, n) {
        REP(i, m) relax(e[i], delta);
        //FOR(i, 1, n) printf("%.5f\n", d[i]);
        //cerr << "\n";
    }
    //FOR(i, 1, n) printf("%.5f\n", d[i]);
    //cerr << "\n";
    REP(i, m) if (relax(e[i], delta)) {
        //cerr << delta << " " << e[i].u << " " << e[i].v << " " << e[i].c << "\n";
        return true;
    }
    return false;
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        e[i].u = u;
        e[i].v = v;
        e[i].c = c;
    }
    double l = 0, r = (1 << 23) + 5, mi, res = r;
    while (r - l > EPS) {
        mi = (l+r)/2;
        if (ok(mi)) {
            res = min(res, mi);
            r = mi - EPS;
        } else l = mi + EPS;
    }
    if (ok(res)) printf("%.2f", res);
    else printf("-1");
    //cerr << ok(6283139.71);
}
/// Expelliarmus !
