using namespace std;
#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 1e6 + 10;
int tc, n, md, f[N], s[N], pos[N];
long long m;
typedef int mat[2][2];
void One(mat &a, int n) {
    for (int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        a[i][j] = i == j;
}
void Copy(const mat a, mat &b, int m, int n) {
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) b[i][j] = a[i][j];
}
void Mul(const mat a, const mat b, mat &c, int m, int n, int p) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < m; i++)
    for (int j = 0; j < p; j++)
    for (int k = 0; k < n; k++)
        c[i][j] = (int) ((c[i][j] + 1LL *a[i][k] * b[k][j]) % (1LL * md));
}
void Exp(const mat a, int _size, long long n, mat &b) {
    mat t, r;
    Copy(a, t, _size, _size);
    One(b, _size);
    while (n) {
        if (n&1) {
            Mul(t, b, r, 2, 2, 2);
            Copy(r, b, 2, 2);
        }
        Mul(t, t, r, 2, 2, 2);
        Copy(r, t, 2, 2);
        /*cout << n << endl;
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) cout << b[i][j] << " \n"[j == 1];*/
        n >>= 1;
    }
}
int main() {
    freopen("fibseq.inp", "r", stdin);
    freopen("fibseq.out", "w", stdout);
    mat base, fib, tmp, big;
        base[0][0] = 0;
        base[0][1] = 1;
        base[1][0] = 1;
        base[1][1] = 1;
        fib[0][0] = 0;
        fib[1][0] = 1;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %lld %d", &n, &m, &md);
        //cout << n << m << md << endl;
        Exp(base, 2, m-1, tmp);
        //cout << "ok\n";
        Mul(tmp, fib, big, 2, 2, 1);
        /*cout << "ok\n";
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) cout << big[i][j] << " \n"[j == 1];*/

        memset(pos, -1, sizeof pos);
        f[0] = big[0][0] % md;
        f[1] = big[1][0] % md;
        //printf("%d %d\n", f[0], f[1]);
        s[0] = 0; s[1] = f[1];
        pos[0] = 0; pos[s[1]] = 1;
        //cout << "ok\n";
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i-1] + f[i-2]) % md;
            s[i] = (s[i-1] + f[i]) % md;
            //cout << s[i] << endl;
            if (pos[s[i]] != -1) {
                printf("%d ", i - pos[s[i]]);
                for (int j = pos[s[i]] + 1; j <= i; j++) printf("%lld ", j + m-1);
                printf("\n");
                break;
            } else pos[s[i]] = i;
        }
        //printf("---\n");
    }
    return 0;
}
