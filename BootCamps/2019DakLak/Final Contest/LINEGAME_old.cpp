#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "LINEGAME"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Point{
    ll x, y;
    operator < (const Point a) {
        if (y != a.y) return y < a.y;
        else return x < a.x;
    }
    Point(): x(0), y(0) {}
    Point(ll _x, ll _y): x(_x), y(_y) {}
};
const int N = 1e5 + 5;
int n, percent, tc, res, root;
int id[N], ord[N];
Point p[N];
double startTime;

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
void sub1() {
    int res = 0;
    FOR(i, 1, n-1) FOR(j, i+1, n) {
        int tmp = 2;
        FOR(k, j+1, n) if (k != i && k != j && ccw(p[i], p[j], p[k]) == 0) tmp ++;
        res = max(res, tmp);
    }
    if (res * 100 >= percent * n) printf("possible\n");
    else printf("impossible\n");
}
int solve() {
    //cerr << "solve " << root << "\n";
    int m = 0;
    FOR(i, root+1, n) id[++m] = i;
    sort(id + 1, id + m + 1, [](int id1, int id2){
        Point a(p[id1].x - p[root].x, p[id1].y - p[root].y);
        Point b(p[id2].x - p[root].x, p[id2].y - p[root].y);
        if (a.x * b.x <= 0) return a.x > b.x;
        else return a.y * b.x < a.x * b.y;
    });
    int res = 2, tmp = 2;
    FOR(i, 2, m) if (ccw(p[root], p[id[i-1]], p[id[i]]) == 0) {
        tmp ++;
        //cerr << root << " " << id[i-1] << " " << id[i] << "\n";
        res = max(res, tmp);
    } else tmp = 2;
    //cerr << res << "\n";
    return res;
}
void sub2() {
    sort(p+1, p+n+1);
    //FOR(i, 1, n) cerr << p[i].x  << " "<< p[i].y << "\n";
    FOR(i, 1, n) ord[i] = i;
    random_shuffle(ord + 1, ord + n + 1);
    res = 0;
    FOR(z, 1, n) {
        root = ord[z];
        res = max(res, solve());
    }
    if (res * 100 >= percent * n) printf("possible\n");
    else printf("impossible\n");
}
void sub3() {
    sort(p+1, p+n+1);
    FOR(i, 1, n) ord[i] = i;
    random_shuffle(ord + 1, ord + n + 1);
    res = 0;
    FOR(z, 1, n) {
        if (((double)clock() - startTime) / CLOCKS_PER_SEC >= 0.85) {
            if (res * 100 >= percent * n) printf("possible\n");
            else printf("impossible\n");
            return;
        }
        root = ord[z];
        res = max(res, solve());
    }
    if (res * 100 >= percent * n) printf("possible\n");
    else printf("impossible\n");
}
int main() {
    startTime = clock();
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while  (tc --) {
        scanf("%d%d", &n, &percent);
        if (n <= 2) {
            printf("possible\n");
            continue;
        }
        FOR(i, 1, n) scanf("%lld%lld", &p[i].x, &p[i].y);
        if (n <= 400) sub1();
        else if (n <= 1000) sub2();
        else sub3();
        //sub2();
        //cerr << res << "\n";
    }
}
