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
    ld x, y, z;
    Point() {}
};

const int N = 1e5 + 5;

int n;
Point u, v, p;
ld a, b, c, h;

ld sqr(ll a) {
    return a * a;
}

ld dist(Point &a, Point &b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    cin >> n;
    cin >> u.x >> u.y >> u.z;
    cin >> v.x >> v.y >> v.z;
    a = dist(u, v);
    FOR(i, 1, n) {
        cin >> p.x >> p.y >> p.z;
        b = dist(p, u); c = dist(p, v);
        h = sqrt((a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c) / (4 * a * a));
        cout << (ll)ceil(h) << '\n';
    }
}
