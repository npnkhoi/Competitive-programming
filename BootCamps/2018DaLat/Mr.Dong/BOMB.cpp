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
const int BASE = 10000;
typedef vector <int> BigInt;

const int N = 35;
const int P = 900 + 5;
int n, m;
int a[N][N], b[N][N];
int pt[P][P];

int sum1(int i, int j) {
    int s = 0;
    if (i > 0) s += b[i-1][j];
    if (i < m-1) s += b[i+1][j];
    if (j > 0) s += b[i][j-1];
    if (j < n-1) s += b[i][j+1];
    return s % 2;
}
void sub1() {
    REP(i, m) REP(j, n) scanf("%d", &a[i][j]);
    int res = 0;
    REP(mask, 1<<(m*n)) {
        bool ok = 1;
        REP(z, (m*n)) b[z/n][z%n] = (mask & (1<<z)) > 0;
        REP(i, m) REP(j, n)
        if (a[i][j] != -1 && sum1(i, j) != a[i][j]) {
            ok = 0;
            break;
        }
        res += ok;
    }
    printf("%d", res);
}
int sum2(int i, int j) {
    int s = 0;
    if (i > 0) s += b[i-1][j];
    if (j > 0) s += b[i][j-1];
    if (j < n-1) s += b[i][j+1];
    return s % 2;
}
void sub2() {
    REP(i, m) REP(j, n) scanf("%d", &a[i][j]);
    int res = 0;
    REP(mask, 1<<n) {
        bool ok = 1;
        REP(j, n) b[0][j] = (mask & (1<<j)) > 0;
        FOR(i, 1, m-1) REP(j, n) {
            b[i][j] = sum2(i-1, j) ^ a[i-1][j];
        }
        REP(j, n) if (a[m-1][j] != sum1(m-1, j)) {
            ok = 0;
        }
        res += ok;
    }
    printf("%d", res);
}
BigInt operator * (const BigInt a, const int mul) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        carry += a[i] * mul; c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}
void Print(const BigInt a) {
    int L = a.size(); printf("%d", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
    printf("\n");
}
void sub3() {
    int k = 0;
    int p = m*n;
    REP(i, m) REP(j, n) {
        int num; scanf("%d", &num);
        if (num != -1) {
            ++ k;
            pt[k][p] = num;
            if (i > 0) pt[k][(i-1)*n+j] = 1;
            if (j > 0) pt[k][i*n+(j-1)] = 1;
            if (i < m-1) pt[k][(i+1)*n+j] = 1;
            if (j < n-1) pt[k][i*n+j+1] = 1;
        }
    }
    int cnt = k;
    FOR(i, 1, k) {
        int flag = -1;
        REP(j, p) if (pt[i][j] != 0) {
            flag = j; break;
        }
        if (flag == -1) {
            if (pt[i][p] != 0) {
                printf("0\n");
                return;
            } else {
                -- cnt; continue;
            }
        }
        FOR(j, i+1 , k) if (pt[j][flag] != 0) {
            FOR(z, 0, p) pt[j][z] = (pt[i][z] + pt[j][z]) % 2;
        }
    }
    int res = p - cnt;
    BigInt ans;
    ans.push_back(1);
    FOR(i, 1, res) {
        ans = ans * 2;
    }
    Print(ans);

}
int main() {
    freopen("BOMB.inp", "r", stdin);
    freopen("BOMB.out", "w", stdout);
    scanf("%d%d", &m, &n);
    /*if (m <= 5 && n <= 5) sub1();
    else if (m <= 20 && n <= 20) sub2();
    else sub3();*/
    sub3();
    return 0;
}
/** Happy Coding ^^ */

