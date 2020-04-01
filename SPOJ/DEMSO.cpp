#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "demso"
typedef long long ll;
//typedef pair<int, int> ii;
const int N = 18;
const int DIGITS = 12;
const int MAXL = 16;

int a[N];
int d, k;

long long f[N][N][DIGITS], g[N][N][DIGITS];
void init() {
    FOR(x, 1, 9) g[1][0][x] = 1;
    FOR(i, 2, MAXL) FOR(j, 0, k) FOR(x, 0, 9) {
        FOR(y, 0, 9) if (abs(x-y) <= d) {
            if (j > 0) g[i][j][x] += g[i-1][j-1][y];
        } else g[i][j][x] += g[i-1][j][y];
        //printf("g(%d, %d, %d) = %lld\n", i, j, x, g[i][j][x]);
    }
}
long long calc(long long val) {
    if (val < 10) return val - 1;
    //printf("calc %lld\n", val);
    int n = 0;
    while (val) {
        a[++ n] = val % 10;
        val /= 10;
    }
    reverse(a+1, a+n+1);
    memset(f, 0, sizeof f);
    FOR(x, 1, a[1]-1) f[1][0][x] = 1;

    int ugly = 0;
    FOR(i, 2, n) {
        FOR(j, 0, k) FOR(x, 0, 9) {
            FOR(y, 0, 9) if (abs(x-y) <= d) {
                if (j > 0) f[i][j][x] += f[i-1][j-1][y];
            } else f[i][j][x] += f[i-1][j][y];
        }
        FOR(x, 0, a[i]-1) {
            int j_ = ugly + (abs(x-a[i-1])<=d);
            //printf("%d %d\n", x, j_);
            if (j_ <= k) {
                f[i][j_][x] ++;
                //cerr << "inc\n";
            }
        }
        ugly += (abs(a[i] - a[i-1]) <= d);
    }
    long long res = 0;
    FOR(i, 1, n-1) FOR(j, 0, k) FOR(x, 0, 9) res += g[i][j][x];
    //cerr << res << "\n";
    FOR(j, 0, k) FOR(x, 0, 9) res += f[n][j][x];
    //printf("return: %lld\n", res);
    return res;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    long long a, b;
    cin >> a >> b >> d >> k;
    init();
    cout << calc(b+1) - calc(a);
}
/// Expelliarmus !
