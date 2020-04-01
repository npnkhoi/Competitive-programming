#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

struct Point {
    long long x, y;
};

int n, m;
Point a[N], b[N];
int sourceL, sourceR, noseL1, noseR1, noseL2, noseR2, res;

int pre(int i) {
    return (i == 1 ? m : i - 1);
}

int nxt(int i) {
    return (i == m ? 1 : i + 1);
}

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

bool inTriangle(Point m, Point a, Point b, Point c) {
    return ccw(a, m, b) <= 0 && ccw(b, m, c) <= 0 && ccw(c, m, a) <= 0;
}

int touchR(int s) {
    for (int i = 1; i <= m; ++ i) {
        if (ccw(a[s], b[i], b[pre(i)]) > 0 && ccw(a[s], b[i], b[nxt(i)]) >= 0) {
            return i;
        }
    }
}

int touchL(int s) {
    for (int i = 1; i <= m; ++ i) {
        if (ccw(a[s], b[i], b[nxt(i)]) < 0 && ccw(a[s], b[i], b[pre(i)]) <= 0) {
            return i;
        }
    }
}



int main() {
    freopen("SENDINFOR.inp", "r", stdin);
    freopen("SENDINFOR.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++ i) {
        scanf("%lld%lld", &b[i].x, &b[i].y);
    }
    int noseL = touchL(1), noseR = touchR(1);
    for (int i = 2; i <= m; ++ i) {
        mark[i] = 1;
        nL = 
        for (int i = 2; i <= m; ++ i)
    }
}
