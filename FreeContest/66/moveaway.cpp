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
const int N = 55;
const double EPS = 0.0000000001;
int a[N], b[N], r[N], n;
int minX = -2000, minY = -2000;
int maxX = 2000, maxY = 2000;

double sqr(double x) {
    return x*x;
}
double dist(double x, double y) {

}
bool ok(double x, double y) {
    FOR(i, 1, n) if (sqr(x-a[i]) + sqr(y-b[i]) > sqr(r[i]))
        return false;
    return true;
}
double find1(double x) {
    //cerr << "1\n";
    double l = minY, r = maxY;
    double res = r;
    while (r - l >= EPS) {
        double mi = (l+r)/2;
        if (ok(x, mi)) {
            res = min(res, mi);
            r = mi - EPS;
        } else l = mi + EPS;
    }
    return res;
}
double find2(double x) {
    //cerr << "2\n";
    double l = minY, r = maxY;
    double res = l;
    while (r - l >= EPS) {
        double mi = (l+r)/2;
        if (ok(x, mi)) {
            res = max(res, mi);
            l = mi + EPS;
        } else r = mi - EPS;
    }
    return res;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d", &n);

    FOR(i, 1, n) {
        scanf("%d%d%d", &a[i], &b[i], &r[i]);
        minX = max(minX, a[i] - r[i]);
        minY = max(minY, b[i] - r[i]);
        maxX = min(maxX, a[i] + r[i]);
        maxY = min(maxY, b[i] + r[i]);
    }
    //printf("%d %d %d %d\n", minX, maxX, minY, maxY);
    double res = 0;
    /*for (double x = minX; x <= maxX; x += EPS)
    for (double y = minY; y <= maxY; y += EPS) if (ok(x, y))
        res = max(res, sqrt(x*x + y*y));
    printf("%.3lf", res);*/
    double l = minX, r = maxX;
    while (r-l >= EPS) {
        double mi = (r+l)/2;

        double y0 = find2(mi);
        double y1 = find2(mi+EPS);

        if (y0 <= y1) {
            res = max(res, sqrt(mi*mi + y1*y1));
            l = mi + EPS;
        } else r = mi - EPS;
    }

    l = minX, r = maxX;
    while (r-l >= EPS) {
        double mi = (r+l)/2;

        double y0 = find1(mi);
        double y1 = find1(mi+EPS);

        if (y0 >= y1) {
            res = max(res, sqrt(mi*mi + y1*y1));
            l = mi + EPS;
        } else r = mi - EPS;
    }


    printf("%.3lf", res);
    return 0;
}
/** Happy Coding :D */
