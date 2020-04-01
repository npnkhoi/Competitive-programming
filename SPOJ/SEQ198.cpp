using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FOD(i, b, a) for (int i = (b); i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
const int N = 2005;
const int MASK = 1024 + 5;
const int oo = N;
int n, m, a[N], f[N][MASK];
ii b[N];
bool _198(int x, int y) {
    int t = abs(x - y);
    return t == 1 || t == 9 || t == 8;
}
bool check(int pos, int mask) {
    if (pos <= 10 && mask >= (1<<(pos+1))) {
        return 0;
    }
    for (int i = 0; (1<<i) <= mask; i++)
    if ((1<<i) & mask) {
        for (int j = i+1; (1<<j) <= mask; j++)
        if ((1<<j) & mask) {
            if (_198(b[pos - i].fi, b[pos - j].fi)) {
                return 0;
            }
        }
    }
    return 1;
}
void sub3() {
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (i > 0 && a[i] == a[i-1]) b[m-1].se ++;
        else b[m++] = mp(a[i], 1);
    for (int i = 0; i < m; i++)
    for (int mask = 0; mask < 1024; mask ++)
    if (check(i, mask)) {
        if (mask & 1) {
            f[i][mask] = 0;
            if (i > 0) {
                f[i][mask] = f[i-1][mask >> 1];
                if (i >= 10 && !_198(b[i].fi, b[i-10].fi))
                f[i][mask] = min(f[i][mask], f[i-1][(1 << 9) + (mask >> 1)]);
            }
        } else {
            f[i][mask] = b[i].se;
            if (i > 0) {
                f[i][mask] = b[i].se +
                min(f[i-1][mask >> 1], f[i-1][(1<<9) + (mask >> 1)]);
            }
        }
    } else {
        f[i][mask] = oo;
    }
    int res = oo;
    for (int j = 0; j < 1024; j++) res = min(res, f[m-1][j]);
    printf("%d\n", res);
    //cerr << res << endl;
}
int main() {
    //freopen("0.inp", "r", stdin);
    //freopen("0.out", "w", stdout);
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    sub3();
    return 0;
}
