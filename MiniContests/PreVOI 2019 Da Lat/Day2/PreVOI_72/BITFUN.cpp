#include <cstdlib>
#include <cstdio>
#include <cstddef>
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

#define REP(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << "\n"

#define task "BITFUN"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int LOG = 30, SMALL = 1e5;

bool f[SMALL + 5], dp[LOG + 4][LOG + 4][LOG + 4][LOG + 4];

bool getBit(ll x, int i) {
    return (x >> i) & 1;
}

int countBit(ll n) {
    int res = 0;
    while (n) {
        res ++;
        n -= (n&-n);
    }
    return res;
}

bool get(int x, int y, int z, int t) {
    if (z > t) swap(z, t);
    if (y > z) swap(y, z);
    if (x > y) swap(x, y);
    return dp[x][y][z][t];
}

void Init() {
    f[0] = 0;
    FOR(mask, 1, SMALL) {
        FORD(x, LOG, 1) if (getBit(mask, x)) {
            FORD(y, x - 1, 0) if (!getBit(mask, y)) {
                f[mask] |= !f[(mask ^ (1 << x)) | (1 << y)];
            }
        }
    }

    FOR(x, 0, LOG + 2) {
        FOR(y, x + 1, LOG + 2) {
            FOR(z, y + 1, LOG + 2) {
                FOR(t, z + 1, LOG + 2) {
                    FOR(w, 0, t - 1) {
                        if (w == x || w == y || w == z) continue;
                        dp[x][y][z][t] |= !get(x, y, z, w);
                        if (w < z) dp[x][y][z][t] |= !get(x, y, w, t);
                        if (w < y) dp[x][y][z][t] |= !get(x, w, z, t);
                        if (w < x) dp[x][y][z][t] |= !get(w, y, z, t);
                    }
                }
            }
        }
    }
}

void answer(bool x) {
    cout << (x ? "YES\n" : "NO\n");
}

void Solve() {
    int tc;
    ll n;
    cin >> tc;
    while (tc --) {
        cin >> n;
        if (countBit(n + 1) == 1) {
            cout << "NO\n";
        } else if (countBit(n) == 1) {
            cout << "YES\n";
        } else if (n <= SMALL) {
            answer(f[n]);
        } else {
            vi pos;
            REP(i, LOG) if (getBit(n, i)) pos.push_back(i);
            int m = pos.size();
            if (m == 2) answer(dp[0][1][pos[0] + 2][pos[1] + 2]);
            else if (m == 3) answer(dp[0][pos[0] + 1][pos[1] + 1][pos[2] + 1]);
            else answer(dp[pos[0]][pos[1]][pos[2]][pos[3]]);
        }
    }
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    Init();
    Solve();
}
