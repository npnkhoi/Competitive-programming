#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <complex>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << '\n'

#define task "BIGBALL"

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

struct Point{
    ll x, y, z;
    Point() {}
};

const int N = 1e5 + 5;
const ld EPS = 1e-17;

int n;
Point u, v, p[N];
ll a, b, c, maxCoor;
ld h;

ll sqr(ll a) {
    return a * a;
}

ld sqr2(ld a) {
    return a * a;
}

ll dist(Point &a, Point &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    cin >> u.x >> u.y >> u.z;
    cin >> v.x >> v.y >> v.z;
    a = dist(u, v);

    ll maxCoor = max(u.x, max(u.y, u.z));
    maxCoor = max(max(maxCoor, v.x), max(v.y, v.z));

    FOR(i, 1, n) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        maxCoor = max(maxCoor, p[i].x);
        maxCoor = max(maxCoor, p[i].y);
        maxCoor = max(maxCoor, p[i].z);
    }

    if (maxCoor <= 100) {
        FOR(i, 1, n) {
            b = dist(p[i], u);
            c = dist(p[i], v);
            ll L = 4 * a;
            ll R = - a*a - b*b - c*c + 2*a*b + 2*b*c + 2*c*a;
            FOR(h, 0, 200) {
                if (L * h * h >= R) {
                    cout << h << '\n';
                    break;
                }
            }
        }
    } else {
        FOR(i, 1, n) {
            cin >> p[i].x >> p[i].y >> p[i].z;
            b = dist(p[i], u); c = dist(p[i], v);
            ld h = - a + 2*b + 2*c - sqr2((b - c) / sqrt((ld)a));
            h = sqrt(h) / 2;
            cout << (ll)ceil(h - EPS) << '\n';
        }
    }
}
