#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)

#define taskname "teaworld"

const int N = 2005;
struct P {
    long long x, y, z;
};

int m, n, k;
bool z0 = 1, del[N];
long long r[N], mtea[N];
P ball[N], shop[N], s;

int dist(P &a, P &b) {
    return  (a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y) +
            (a.z - b.z) * (a.z - b.z);
}
long long triArea(P &a, P &b, P &c) {
    long long s = 0;
    s += a.x * b.y - a.y * b.x;
    s += b.x * c.y - b.y * c.x;
    s += c.x * a.y - c.y * a.x;
    return abs(s);
}
bool inter(P &A, P &B, P &C, ll r) {
    /*cerr << A.x << " " << A.y << " " << A.z << " " << "\n";
    cerr << B.x << " " << B.y << " " << B.z << " " << "\n";
    cerr << C.x << " " << C.y << " " << C.z << " " << "\n";*/
    //cerr << r << "\n";
    long long AB = dist(A, B);
    long long AC = dist(A, C);
    long long BC = dist(B, C);
    //cerr << AB << " " << AC << " " << BC << "\n";
    if (AB <= r*r && AC > r*r) return 1;
    if (AB > r*r && AC <= r*r) return 1;
    if (AB <= r*r && AC <= r*r) return 0;
    //cerr << "ok\n";

    if (z0) {
        long long s = triArea(A, B, C);
        return (AB <= AC + BC && AC <= AB + BC && s*s <= r * r * BC);
    }
    else {
        double p = (sqrt(AB) + sqrt(BC) + sqrt(AC)) / 2;
        //cerr << p << "\n";
        double s = 2 * sqrt(p*(p - sqrt(BC)) * (p - sqrt(AC)) * (p - sqrt(AB)));
        /*cerr << s << "\n";
        cerr << BC << "\n";
        cerr << (AB <= AC + BC) << "\n";
        cerr << (AC <= AB + BC) << "\n";
        cerr << (s*s <= r * r * BC) << "\n";
        cerr << s*s << " " << r*r*BC << "\n";*/
        return (AB <= AC + BC && AC <= AB + BC && s*s <= r * r * BC);
    }
}

bool biton(int mask, int i) {
    return (mask & (1 << i)) > 0;
}
void show(int mask) {
    FOR(i, 0, n-1) cerr << biton(mask, i) << ' ';
    cerr << '\n';
}

int main() {
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    FOR(i, 1, m) {
        scanf("%lld%lld%lld%lld", &ball[i].x, &ball[i].y, &ball[i].z, &r[i]);
        z0 &= (ball[i].z != 0);
    }
    REP(i, n) {
        scanf("%lld%lld%lld%lld", &shop[i].x, &shop[i].y, &shop[i].z, &mtea[i]);
        z0 &= (shop[i].z != 0);
    }
    scanf("%lld%lld%lld", &s.x, &s.y, &s.z);
    z0 &= (s.z != 0);

    //FOR(i, 1, m) cerr << ball[i].x << " " << ball[i].y << " " << ball[i].z << "\n";
    //cerr << pos(s, ball[4], r[4]) << '\n';
    //cerr << pos(shop[1], ball[4], r[4]) << "\n";

    //cerr << inter(ball[3], s, shop[1], r[3]);
    //cerr << inter(ball[2], s, shop[0], r[2]) << "\n";
    long long res = 0;
    REP(mask, (1 << n)) {
        memset(del, 0, sizeof del);
        int cnt = 0;
        long long tmp = 0;
        //printf("mask : %d\n", mask);
        REP(i, n) if (biton(mask, i)) {
            tmp += mtea[i];
            FOR(j, 1, m)
            if (inter(ball[j], s, shop[i], r[j])) {
                //cerr << i << " " << j << "\n";
                del[j] = 1;
            }
        }
        //show(mask);
        //FOR(i, 1, m) cerr << del[i] << " "; cerr << "\n";

        FOR(j, 1, m) if (del[j]) cnt ++;
        if (cnt <= k) {
            //cerr << tmp << '\n';
            res = max(res, tmp);
        }
    }
    printf("%lld\n", res);
}
