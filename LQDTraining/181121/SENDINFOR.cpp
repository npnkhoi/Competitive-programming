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
    for (int i = 1; i <= m; ++ i) {
        if (ccw(a[1], b[i], b[pre(i)]) > 0 && ccw(a[1], b[i], b[nxt(i)]) >= 0) {
            noseR1 = i;
            break;
        }
    }
    for (int i = 1; i <= m; ++ i) {
        if (ccw(a[1], b[i], b[nxt(i)]) < 0 && ccw(a[1], b[i], b[pre(i)]) <= 0) {
            noseL1 = i;
            break;
        }
    }
    // cerr << noseL1 << " " << noseR1 << "\n";
    sourceL = 1;
    sourceR = 1;
    noseL2 = noseL1;
    noseR2 = noseR1;
    for (int i = 2; i <= n; ++ i) {
        if (ccw(a[1], b[noseR1], a[i]) > 0) continue; // check mayday
        if (ccw(a[sourceR], b[noseR2], a[i]) > 0) continue;
        sourceR = i;

        while (!(ccw(a[sourceR], b[noseR2], b[pre(noseR2)]) > 0
            && ccw(a[sourceR], b[noseR2], b[nxt(noseR2)]) >= 0)) noseR2 = nxt(noseR2);
    }
    for (int i = 2; i <= n; ++ i) {
        if (ccw(a[1], b[noseL1], a[i]) < 0) continue;
        if (ccw(a[sourceL], b[noseL2], a[i]) < 0) continue;
        sourceL = i;
         while (!(ccw(a[sourceL], b[noseL2], b[nxt(noseL2)]) < 0
            && ccw(a[sourceL], b[noseL2], b[pre(noseL2)]) <= 0)) noseL2 = pre(noseL2);
    }
    // cerr << sourceL <<  " " << noseL2 << "\n";
    // cerr << sourceR <<  " " << noseR2 << "\n";
    //cerr << "---------\n";
    for (int i = 2; i <= n; ++ i) {
        if (inTriangle(a[i], a[1], b[noseR1], b[noseL1])) {
            //cerr << i << " 1\n";
            res ++;
        } else if (inTriangle(a[i], a[1], a[sourceR], b[noseR2])) {
            res ++;
        } else if (inTriangle(a[i], a[1], b[noseL2], a[sourceL])) {
            res ++;
        } else if (ccw(a[1], b[noseR1], a[i]) <= 0) {
            //cerr << i << " 2\n";
            res ++;
        } else if (ccw(a[1], b[noseL1], a[i]) >= 0) {
            //cerr << i << " 3\n";
            res ++;
        } else if (ccw(a[sourceR], b[noseR2], a[i]) <= 0) {
            //cerr << i << " 4\n";
            res ++;
        } else if (ccw(a[sourceL], b[noseL2], a[i]) >= 0) {
            //cerr << i << " 5\n";
            res ++;
        }
    }
    printf("%d\n", res);
}
