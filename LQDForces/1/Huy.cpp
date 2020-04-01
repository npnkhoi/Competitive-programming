/**
 *  author: rknguyen
 *  created: 18/11/2018 08:07:27 +07
**/

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define sqr(x) ((x) * (x))
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(), x.end())
#define REP(i, a) for(int i = 0; i < (a); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FOD(i, a, b) for(int i = (a); i >= (b); --i)
#define RED(i, a) for (int i = (a - 1); i >= 0; --i)
#define debug(x) cerr << #x << " = " << x << '\n';
#define BP( ) cerr << "OK!\n";
#define PR(A, n) {cerr << #A << " = "; for (int _=1; _<=n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; for (int _=0; _<n; ++_) cerr << A[_] << ' '; cerr << '\n';}

#define EPS 1e-6
const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

inline int cmp(long double a, long double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point {
    long double x, y;
    Point() { x = y = 0.0; }
    Point(long double x, long double y) : x(x), y(y) {}

    // operators on point
    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (long double k) const { return Point(x*k, y*k); }
    Point operator / (long double k) const { return Point(x/k, y/k); }
    long double operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    long double operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product
 
    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }
    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    Point conj() { return Point(x, -y); }
    long double norm() { return x * x + y * y; }
    long double len() { return sqrt(norm()); }
};

istream& operator >> (istream& cin, Point& p) {
    cin >> p.x >> p.y;
    return cin;
}

ostream& operator << (ostream& cout, Point& p) {
    cout << p.x << ' ' << p.y;
    return cout;
}

// Distance from p to Line ab (closest Point --> c)
long double distToLine(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    long double u = (ap * ab) / ab.norm();
    c = a + (ab * u);
    return (p-c).len();
}

// Distance from p to segment ab (closest Point --> c)
long double distToLineSegment(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    long double u = (ap * ab) / ab.norm();
    if (u < 0.0) {
        c = Point(a.x, a.y);
        return (p - a).len();
    }
    if (u > 1.0) {
        c = Point(b.x, b.y);
        return (p - b).len();
    }
    return distToLine(p, a, b, c);
}

// dist from C to A,B
long double lenOfSegment(Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
long double distToSegment(Point A, Point B, Point C) {
    long double area = fabs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)));
    return area / (2.0 * lenOfSegment(A, B));
}

/*
3
-2 3 1 2
4 5 1 1
1 -1 1 2
2
1 1
2 2
*/

int main() 
{
    freopen("A.inp", "r", stdin);
    freopen("huy.txt", "w", stdout);
    int n; cin >> n;
    vector<int>d(n);
    vector<long double>r(n);
    vector<Point> info(n);
    REP(i, n) {
        cin >> info[i];
        cin >> d[i] >> r[i];
    }
    int m; cin >> m;
    vector<Point> p(m + 1);
    REP(i, m) cin >> p[i]; 
    
    Point tmp;
    int64_t res = 0;
    vector<bool>mark(n, 0);
    FOR(i, 1, m - 1) REP(j, n) if (!mark[j]) {
        long double dist = distToLineSegment(info[j], p[i - 1], p[i], tmp);
        if (dist <= r[j]) {
            res += (int64_t)d[j];
            mark[j] = 1;
        }
    }

    cout << res << '\n';
    return 0;
}
