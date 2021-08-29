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
#define task "VECTOR"
typedef long long lint;
typedef unsigned long long ul;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef vector<int> vi;

int m, n, x, res;
map<int, int> a, b;
map<int, int>::iterator ita, itb;
vector<pair<ii, ii> > game;

void process(int val, int y, int x) {
    if (val == 1) return;
    //cerr << val << ' ' << x << ' ' << y << '\n';
    int a = (x + 1) / 2, b, c;
    if ((a + y) % 2) a ++;
    c = 2 * a - x;
    b = (a + y) / 2;
    res += a + b + c;
    //cerr << a << ' ' << b << ' ' << c << '\n';
    game.push_back(mp(mp(val, a), mp(b, c)));
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m;
    FOR(i, 1, m) {
        cin >> x;
        a[x] ++;
    }
    cin >> n;
    FOR(i, 1, n) {
        cin >> x;
        b[x] ++;
    }
    for (ita = a.begin(), itb = b.begin(); ita != a.end() || itb != b.end(); ) {
        //cerr << "current: " << (ita == a.end()) << ' ' << (itb == b.end()) << '\n';
        if (itb == b.end()) {
            process(ita -> X, ita -> Y, 0);
            ++ ita;
            //cerr << "1\n";
        } else if (ita == a.end()) {
            process(itb -> X, 0, itb -> Y);
            ++ itb;
            //cerr << "2\n";
        } else if (ita -> X < itb -> X) {
            process(ita -> X, ita -> Y, 0);
            ++ ita;
        } else if (ita -> X > itb -> X) {
            process(itb -> X, 0, itb -> Y);
            ++ itb;
        } else {
            process(ita -> X, ita -> Y, itb -> Y);
            ++ita; ++itb;
            //cerr << "1 + 2\n";
        }
    }
    cout << res << '\n';
    REP(i, game.size()) {
        int val = game[i].X.X, a = game[i].X.Y, b = game[i].Y.X, c = game[i].Y.Y;
        REP(i, c) cout << val << " D\n";
        REP(i, a) cout << val << " W\n";
        REP(i, b) cout << val << " L\n";
    }
}
