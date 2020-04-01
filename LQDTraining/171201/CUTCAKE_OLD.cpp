#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define taskName "cutcake"

const int N = 3e5 + 5;
struct P {
    ll x, y;
};
bool cmp(P a, P b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int m, n, p;
double timer;
ll curArea = 0, maxArea = 0;
P a[N], tmp[N], b[N];

ll ccw(P &a, P &b, P &c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
void convexHull(P a[], int n, P b[], int &m) {
    m = 0;
    FOR(i, 1, n) {
        while (m >= 2 && ccw(b[m-1], b[m], a[i]) <= 0) m --;
        b[++m] = a[i];
    }
    int flag = m;
    FORD(i, n, 1) {
        while (m > flag && ccw(b[m-1], b[m], a[i]) <= 0) m --;
        b[++m] = a[i];
    }
    while (m > 3 && ccw(b[m-1], b[m], b[1]) == 0) m --;
}
int pre(int x, int m) {
    if (x == 1) return m;
    else return x - 1;
}
int nex(int x, int m) {
    if (x == m) return 1;
    else return x + 1;
}
int checkTangent(int x, int y) {
    ll s1 = ccw(a[x], b[y], b[pre(y, m)]);
    ll s2 = ccw(a[x], b[y], b[nex(y, m)]);

    if (s1 <= 0 && s2 <= 0) return 1;
    else if (s1 >= 0 && s2 >= 0) return 2;
    else if (s1 > 0) return -1;
    else return -2;
}
ll triArea(P &a, P &b, P &c) {
    ll res = 0;
    res += a.x * b.y - a.y * b.x;
    res += b.x * c.y - b.y * c.x;
    res += c.x * a.y - c.y * a.x;
    return abs(res);
}
void checkTime() {
    if ((clock() - timer)/CLOCKS_PER_SEC >= 0.9) {
        printf("%lld", maxArea);
        exit(0);
    }
}
int main() {
    timer = clock();
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld%lld", &a[i].x, &a[i].y);
    scanf("%d", &p);
    FOR(i, 1, p) scanf("%lld%lld", &tmp[i].x, &tmp[i].y);
    sort(tmp+1, tmp+p+1, cmp);

    if (p <= 2) {
        m = p;
        FOR(i, 1, m) b[i] = tmp[i];
    } else convexHull(tmp, p, b, m);
    /*FOR(i, 1, m) {
        cerr << b[i].x << " " << b[i].y << "\n";
    }*/
    int y = 1, z = 1;
    //cerr << "m = " << m << "\n";
    FOR(x, 1, n) {
        //cerr << "------\n";
        //cerr << checkTangent(x, y) << "\n";
        //cerr << "x = " << x  << "\n";
        checkTime();
        if (m >= 2)
            while (checkTangent(x, y) != 2) {
                y = nex(y, m);
                //cerr << "y - > " << y << "\n";
            }

        //cerr << "y = " << y << "\n";
        int prex = pre(x, n);
        curArea -= triArea(a[prex], a[x], a[z]);
        //cerr << curArea << "\n";
        //cerr << "cur Z = " << z  << "\n";
        //cerr << x << " " << y << " " << nex(z, n) << "\n";
        //cerr << ccw(a[x], b[y], a[nex(z, n)]) << "\n";
        checkTime();
        while (ccw(a[x], b[y], a[nex(z, n)]) < 0) {
            //cerr << "move to " << z << "\n";
            curArea += triArea(a[x], a[z], a[nex(z, n)]);
            z = nex(z, n);
        }
        maxArea = max(maxArea, curArea);
        //cerr << x << " " << y << " " << z << "\n";
        //cerr << curArea << "\n";
    }
    //printf("%lld.%lld\n", maxArea/2, maxArea%2*5);
    printf("%lld", maxArea);
    return 0;
}
/** Happy Coding :D */
