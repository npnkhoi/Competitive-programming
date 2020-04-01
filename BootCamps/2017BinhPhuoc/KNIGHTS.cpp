#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

const int N = 260;
const int M = 6;
const ll md = 1e9 + 9;
typedef ll mat[N][N];
#define taskName "knights"

int m, n;
mat base0, base, f0, f;
bool board[M][M];

void Mul(mat &a, mat &b, mat &c, int m, int n, int p) {
    REP(i, m) REP(k, p) {
        c[i][k] = 0;
        REP(j, n) c[i][k] = (c[i][k] + a[i][j] * b[j][k]) % md;
    }
}
void copy(mat &a, mat &b, int m, int n) {
    REP(i, m) REP(j, n) b[i][j] = a[i][j];
}
void show(mat a, int n) {
    cerr << "show \n";
    REP(i, n) {
        REP(j, n) cerr << a[i][j] << " ";
        cerr << "\n";
    }
}
void Pow(mat &a, mat &b, int x, int n) {
    mat tmp, base;
    copy(a, base, n, n);
    memset(b, 0, sizeof b);
    REP(i, n) b[i][i] = 1;

    while (x) {
        if (x&1) {
            Mul(b, base, tmp, n, n, n);
            copy(tmp, b, n, n);
        }
        Mul(base, base, tmp, n, n, n);
        copy(tmp, base, n, n);
        x >>= 1;
    }
}
int col1(int mask, int m) {
    return mask >> m;
}
int col2(int mask, int m) {
    return mask & ((1 << m) - 1);
}
bool ok(int mask, int m) {
    int c1 = col1(mask, m);
    int c2 = col2(mask, m);
    return !(((c1 >> 2) & c2) || c1 & (c2 >> 2));
}
bool match(int mask1, int mask2, int m) {
    if (col2(mask1, m) != col1(mask2, m)) return 0;
    int c1 = col1(mask1, m);
    int c3 = col2(mask2, m);
    return !(((c1 >> 1) & c3) || c1 & (c3 >> 1));
}

int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d%d", &m, &n);

    vi state;
    REP(mask, 1 << (2*m)) if (ok(mask, m)) state.pb(mask);
    int p = state.size();

    REP(i, p) REP(j, p)
        if (match(state[i], state[j], m)) base0[i][j] = 1;
    f0[0][0] = 1;

    Pow(base0, base, n, p);
    Mul(base, f0, f, p, p, 1);

    ll res = 0;
    REP(i, p) res = (res + f[i][0]) % md;
    printf("%lld\n", res);

    return 0;
}
/** Happy Coding :D */
