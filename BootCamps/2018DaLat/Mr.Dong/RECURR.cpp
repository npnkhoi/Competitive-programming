using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)

const int N = 50 + 3;
typedef int mat[N][N];

int b[N];
mat base, base2, base3, kq;

void show(mat a, int m, int n) {
    printf("matrix:\n");
    FOR(i, 1, m) {
        FOR(j, 1, n) printf("%5d", a[i][j]);
        cout << endl;
    }
}
void copy(const mat &x, mat &y, int m, int n) {
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) y[i][j] = x[i][j];
}
void matMul(const mat &x, const mat &y, mat &z, int m, int n, int k) {
    FOR(i, 1, m)
    FOR(j, 1, k) {
        z[i][j] = 0;
        FOR(k, 1, n)
            z[i][j] = (z[i][j] + x[i][k] * y[k][j]) % 3;
    }
}
void matPow(const mat &a, int b, mat &c, int n) {
    mat t, r;
    copy(a, t, n, n);
    memset(c, 0, sizeof c);
    FOR(i, 1, n) c[i][i] = 1;
    while (b) {
        if (b & 1) {
            matMul(c, t, r, n, n, n);
            copy(r, c, n, n);
        }
        matMul(t, t, r, n, n, n);
        copy(r, t, n, n);
        b >>= 1;
    }
}
int main() {
    freopen("RECURR.inp", "r", stdin);
    freopen("RECURR.out", "w", stdout);
    int n, d, tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &d);

        memset(base, 0, sizeof base);
        memset(base3, 0, sizeof base3);
        FOR(i, 1, d-1) base[i][i+1] = 1;
        base[d][1] = 1;
        FOR(i, 2, d) base[d][i] = 2;
        //show(base, d, d);
        //cout << n << " " << d << endl;
        matPow(base, n-1, base2, d);
        //show(base2, d, d);

        int num;
        FOD(i, d, 1) {
            scanf("%d", &num);
            if (num == -1) num = 0;
            base3[i][1] = num;
        }
        //show(base3, d, d);

        matMul(base2, base3, kq, d, d, d);
        //show(kq, d, d);

        FOD(i, d, 1) printf("%d ", kq[i][1]);
        printf("\n");
    }
    return 0;
}
/** Happy Coding ^^ */

