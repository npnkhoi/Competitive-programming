#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "LAWRENCE"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 505;
const ll oo = 1e8 + 7;
int n, m;
int a[N];
ll s[N], p[N], f[N][N];
ll calc(int l, int r) {
    return ((s[r] - s[l-1]) * (s[r] - s[l-1]) - (p[r] - p[l-1])) / 2;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
        p[i] = p[i-1] + a[i] * a[i];
    }
    FOR(j, 1, n) f[1][j] = calc(1, j);
    FOR(i, 2, m+1) {
        FOR(j, i, n) {
            f[i][j] = oo;
            FOR(k, i-1, j-1) f[i][j] = min(f[i][j], f[i-1][k] + calc(k+1, j));
        }
    }
    printf("%lld", f[m+1][n]);
}
