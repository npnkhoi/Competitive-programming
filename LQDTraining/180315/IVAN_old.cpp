using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 105;
int n, a[N], b[N], s[N], f[N][N], res;
int sum(int l, int r) {
    if (l == 0) return s[r];
    else return s[r] - s[l-1];
}
int main() {
    //freopen("IVAN.inp", "r", stdin);
    //freopen("IVAN.out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 0, n-1) {
        scanf("%d", &b[i]);
        b[i] %= 2;
    }

    FOR(pos, 0, n-1) {
        FOR(i, 0, n-1) a[i] = b[(pos + i) % n];

        s[0] = a[0];
        FOR(i, 1, n-1) s[i] = s[i-1] + a[i];
        FOR(j, 0, n-1) {
            f[j][j] = a[j];
            FOD(i, j-1, 0)
            f[i][j] = sum(i, j) + max( -f[i+1][j], -f[i][j-1]);
        }
        res += (2 * f[1][n-1] < sum(0, n-1));
    }
    cout << res;
    return 0;
}
/** Happy Coding ^^ */
