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
#define task "WEDDING"
typedef long long lint;
typedef unsigned long long ul;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef vector<int> vi;

const int K = 15e5 + 5;

int k, md;
lint p[K], s[K], t[K], rev[K], col[K], row[K];

lint Exp(lint a, lint n) {
    if (n == 0) return 1;
    lint res = Exp(a, n / 2);
    res = res * res % md;
    if (n & 1) res = res * a % md;
    return res;
}

void init() {
    FOR(i, 1, md) rev[i] = Exp(i, md - 2);
}

void calc(int m) {
    int n = k / m;

    int xx = -1, yy = -1;
    REP(i, m) REP(j, n) {
        if (p[i * n + j]) {
            xx = i;
            yy = j;
        }
    }
    if (xx == -1) {
        cout << "YES\n";
        cout << m << ' ';
        REP(i, m) cout << "0 ";
        cout << '\n';
        cout << n << ' ';
        REP(i, n) cout << "0 ";
        cout << '\n';
        exit(0);
    }
    REP(i, m) REP(j, n) {
        if (p[i * n + j] == 0) continue;
        if (p[i*n+j] * p[xx*n+yy] % md != p[i*n+yy] * p[xx*n+j] % md) return;
    }
    s[xx] = 1;
    t[yy] = p[xx*n+yy];
    lint revS = 1, revT = Exp(t[yy], md - 2);

    REP(i, m) {
        if (i == xx) continue;
        s[i] = p[i*n+yy] * revT % md;
    }
    REP(j, n) {
        if (j == yy) continue;
        t[j] = p[xx*n+j];
    }
    cout << "YES\n";

    cout << m << ' ';
    REP(i, m) cout << s[i] << ' ';
    cout << '\n';

    cout << n << ' ';
    REP(i, n) cout << t[i] << ' ';
    cout << '\n';
    exit(0);
}

void checkZero() {
    REP(i, k) if (p[i] == 0) return;

}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k >> md;
    //init();
    REP(i, k) cin >> p[i];
    FOR(i, 2, sqrt(k)) {
        if (k % i) continue;
        calc(i);
        calc(k / i);
    }
    cout << "NO\n";
}

