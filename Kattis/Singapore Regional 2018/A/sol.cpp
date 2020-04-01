#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Point {
    ll x, y;
    Point() {}
};

const int N = 5005;

int n;
Point a[N];
vector<Point> hull;

bool cmp(Point &a, Point &b) {
    if (a.x != b.x) return a.x < b.x;
    else return (a.y < b.y);
}

ll ccw(Point &a, Point &b, Point &c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

ll area(Point &a, Point &b, Point &c) {
     return abs(
                a.x * b.y - a.y * b.x +
                b.x * c.y - b.y * c.x +
                c.x * a.y - c.y * a.x);
}

int nxt(int i, int n) {
    i ++;
    if (i == n) i = 0;
    return i;
}

void convex() {
    sort(a + 1, a + n + 1, cmp);
    FOR(i, 1, n) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), a[i]) >= 0)
            hull.pop_back();
        hull.push_back(a[i]);
    }
    int flag = hull.size();
    FORD(i, n, 2) {
        while (hull.size() > flag && ccw(hull[hull.size() - 2], hull.back(), a[i]) >= 0)
            hull.pop_back();
        hull.push_back(a[i]);
    }
}

void solve() {
    ll res = 0;
    if (hull.size() <= 2) {
        cout << 0;
        exit(0);
    }
    int m = hull.size();
    REP(i, m) {
        int j, k;
        j = k = nxt(i, m);
        while (i != j) {
            while (area(hull[i], hull[j], hull[k]) < area(hull[i], hull[j], hull[nxt(k, m)]))
                k = nxt(k, m);
            res = max(res, area(hull[i], hull[j], hull[k]));
            j = nxt(j, m);
        }
    }
    cout << res/2 << '.' << res % 2 * 5;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;
    convex();
    REP(i, hull.size()) cerr << hull[i].x << " " << hull[i].y << "\n";
    solve();
}

