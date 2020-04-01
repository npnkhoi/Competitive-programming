#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "BUMERAN"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 255;
vi f[N][N], res;
int n;

char s[N];
const int BASE = 10000;
typedef vector <int> BigInt;
void Print(const BigInt a) {
    if (a.empty()) {
        printf("0\n");
        return;
    }
    int L = a.size(); printf("%d", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
    printf("\n");
}
BigInt operator + (const BigInt a, const BigInt b) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size() || i < (int)b.size(); i++) {
        if (i < (int)a.size()) carry += a[i];
        if (i < (int)b.size()) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}

void spread(int i, int c) {
    FOR(j, i+1, n) {
        if (s[j] == 'F') {
            f[j][c+1] = f[j][c+1] + f[i][c];
            break;
        }
    }
    if (c > 0) FOR(j, i+1, n) {
        if (s[j] == 'R') {
            f[j][c-1] = f[j][c-1] + f[i][c];
            break;
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%s", s+1);
    n = strlen(s+1);
    vi one; one.assign(1, 1);
    f[0][0] = one; spread(0, 0);
    FOR(i, 1, n) FOR(c, 0, n) if (!f[i][c].empty()) spread(i, c);
    FOR(i, 1, n) res = res + f[i][0];
    Print(res);
}
