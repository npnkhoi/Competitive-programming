#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <iterator>
#include <utility>
#include <complex>
#include <bitset>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,a,b) for (int i = a; i >= b; -- i)
#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " = " << x << '\n'
#define task "SIGNAL"
typedef long long lint;
typedef unsigned long long ul;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef vector<int> vi;

const int N = 5e4 + 5, MAXCOOR = 1e7;
const long double EPS = 1e-9, oo = 1e9;

int n, k, x[N], y[N], s[N];

bool ok(long double val) {
    long double minX = -oo, minY = -oo, maxX = oo, maxY = oo;
    FOR(i, 1, n) {
        long double d = val * s[i];
        //debug(d);
        if (d > oo) return true;
        //cerr << "pass\n";
        minX = max(minX, x[i] - y[i] + MAXCOOR - d);
        maxX = min(maxX, x[i] - y[i] + MAXCOOR + d);
        minY = max(minY, x[i] + y[i] - d);
        maxY = min(maxY, x[i] + y[i] + d);
        if (minX > maxX) return false;
        if (minY > maxY) return false;
    }
    return true;
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> x[i] >> y[i] >> s[i];
    }
    long double l = 0, r = 1e9, mid, bs = r;
    while (r - l > EPS) {
        //cerr << fixed << setprecision(12) << l << ' ' << r << '\n';
        mid = (l + r) / 2;
        //cerr << fixed << setprecision(12) << mid << '\n';
        if (ok(mid)) {
            bs = mid;
            r = mid - EPS;
        } else l = mid + EPS;
    }
    cout << fixed << setprecision(15) << bs;
}

