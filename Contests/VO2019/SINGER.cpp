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
#define task "SINGER"
typedef long long lint;
typedef unsigned long long ul;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef vector<int> vi;

bool getBit(int x, int i) {
    return x >> i & 1;
}

void show(int x) {
    if (x != 0) {
        show(x / 2);
        cerr << x % 2;
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, d, t, res = 0;
    cin >> n >> d >> t;
    REP(mask, (1 << n)) {
        int last = 0, cnt = 0;
        if (d == 2) cnt = 1;
        FOR(i, 1, n - 1) {
            if (getBit(mask, i) == getBit(mask, i - 1)) {
                last = i;
            } else {
                if (i - last >= d - 2) {
                    cnt ++;
                }
            }
        }
        if (cnt == t) {
                res ++;
                //show(mask);
                //cerr << endl;
        }
    }
    cout << res;
}

