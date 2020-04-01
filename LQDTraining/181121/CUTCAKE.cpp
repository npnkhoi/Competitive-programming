#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

struct Point {
    long long x, y;
};

int n, m, p;
Point a[N], b[N], hull[N];

bool cmp(Point a, Point b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

long long triArea(Point a, Point b, Point c) {
    long long s = 
      a.x * b.y - a.y * b.x
    + b.x * c.y - b.y * c.x
    + c.x * a.y - c.y * a.x;
    return abs(s);
}

void input() {
    freopen("CUTCAKE.inp", "r", stdin);
    freopen("CUTCAKE.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++ i) {
        scanf("%lld%lld", &b[i].x, &b[i].y);
    }
}

void convexHull() {
    p = 0;
    sort(b + 1, b + m + 1, cmp);
    for (int i = 1; i <= m; ++ i) {
        while (p >= 2 && ccw(hull[p - 1], hull[p], b[i]) <= 0) {
            -- p;
        }
        hull[++ p] = b[i]; 
    }
    int flag = p;
    for (int i = m; i >= 1; -- i) {
        while (p > flag && ccw(hull[p - 1], hull[p], b[i]) <= 0) {
            -- p;
        }
        hull[++ p] = b[i];
    }
    -- p;
}

int pre(int i, int n) {
    if (i == 1) return n;
    else return i - 1;
}

int nxt(int i, int n) {
    if (i == n) return 1;
    else return i + 1;
}

void solve() {
    int pin = 1, pout = 1;
    long long s = 0, res = 0;
    for (int i = 1; i <= n; ++ i) {
        s -= triArea(a[pout], a[i], a[pre(i, n)]);
        while (!(ccw(a[i], hull[pin], hull[pre(pin, p)]) >= 0 &&
        ccw(a[i], hull[pin], hull[nxt(pin, p)]) >= 0)) {
            pin = nxt(pin, p);
        }
        if (pout == pre(i, n)) pout = i;
        while (ccw(a[i], hull[pin], a[nxt(pout, n)]) < 0) {
            s += triArea(a[i], a[pout], a[nxt(pout, n)]);
            pout = nxt(pout, n);
        }
        res = max(res, s);
    }
    printf("%lld\n", res);
}

int main() {
    input();
    convexHull();
    solve();
}
