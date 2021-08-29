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
#define task "TIGERSUGAR"
typedef long long lint;
typedef unsigned long long ul;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef vector<int> vi;

const int N = 1e5 + 5;

ii a[N], b[N], pos[N];
int n, xx, yy;
vi l, r;
lint res;

void calc(ii a[], int &res) {
    l.clear(); r.clear();
    FOR(i, 1, n) {
        r.push_back(a[i].X);
        l.push_back(a[i].Y);
    }
    sort(all(l));
    sort(all(r));

    int best = n;
    FOR(i, 1, n) {
        int lo, hi;
        lo = lower_bound(all(l), a[i].X) - l.begin();
        hi = r.end() - upper_bound(all(r), a[i].X);
        //cerr << a[i].X << ' ' << lo << ' ' << hi << '\n';
        if (abs(lo - hi) < best) {
            best = abs(lo - hi);
            res = a[i].X;
        } else if (abs(lo - hi) == best && lo >= hi) {
            res = a[i].X;
        }

        lo = lower_bound(all(l), a[i].Y) - l.begin();
        hi = r.end() - upper_bound(all(r), a[i].Y);
        //cerr << a[i].Y << ' ' << lo << ' ' << hi << '\n';
        if (abs(lo - hi) < best) {
            best = abs(lo - hi);
            res = a[i].Y;
        } else if (abs(lo - hi) == best && lo <= hi) {
            res = a[i].Y;
        }
    }
    //cerr << endl;
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].X >> b[i].X >> a[i].Y >> b[i].Y;
        if (a[i].X > a[i].Y) swap(a[i].X, a[i].Y);
        if (b[i].X > b[i].Y) swap(b[i].X, b[i].Y);
    }
    calc(a, xx);
    calc(b, yy);
    FOR(i, 1, n) {
        //cerr << a[i].X << ' ' << a[i].Y << ' ' << b[i].X << ' ' << b[i].Y << '\n';
        if (xx < a[i].X) pos[i].X = a[i].X;
        else if (xx > a[i].Y) pos[i].X = a[i].Y;
        else pos[i].X = xx;

        if (yy < b[i].X) pos[i].Y = b[i].X;
        else if (yy > b[i].Y) pos[i].Y = b[i].Y;
        else pos[i].Y = yy;

        res += abs(xx - pos[i].X) + abs(yy - pos[i].Y);
     }
     cout << res << '\n' << xx << ' ' << yy << '\n';
     FOR(i, 1, n) cout << pos[i].X << ' ' << pos[i].Y << '\n';
}
