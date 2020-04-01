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

ifstream fi("INSIDE.inp");
ofstream fo("INSIDE.out");
const int N = 1e5 + 5;
struct point {
    ll x, y;
};

vector<point> v;

long long ccw(point &a, point &b, point &c) {
    return (b.x - a.x)*(c.y - b.y) - (c.x - b.x)*(b.y - a.y);
}
bool inHull(point p, vector<point> &v) {
    int l = 1, r = v.size() - 1;
    int res = r;
    while (l <= r) {
        int mi = (l+r)/2;
        if (ccw(v[0], p, v[mi]) >= 0) {
            res = min(res, mi);
            r = mi-1;
        } else l = mi+1;
    }
    if ((ccw(v[0], p, v[res])) < 0) return false;
    else return ccw(v[res], p, v[res-1]) >= 0;
}

int main() {
    int n;
    fi >> n;
    v.resize(n);
    REP(i, n) fi >> v[i].x >> v[i].y;

    int q;
    fi >> q;
    point p;
    while (q --) {
        fi >> p.x >> p.y;
        if (inHull(p, v)) fo << "Inside\n";
        else fo << "Outside\n";
    }
    return 0;
}
/** Happy Coding :D */
