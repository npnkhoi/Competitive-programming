using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e3 + 5;
const int A = 1e6 + 5;
int cnt[A];
int a[N][N];

int mx(int a, int b, int c, int d) {
    ++ cnt[a]; ++ cnt[b]; ++ cnt[c]; ++ cnt[d];
    int res = max(max(cnt[a], cnt[b]), max(cnt[c], cnt[d]));
    -- cnt[a]; -- cnt[b]; -- cnt[c]; -- cnt[d];
    return res;
}
int main() {
    freopen("MATRIX.inp", "r", stdin);
    freopen("MATRIX.out", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) scanf("%d", &a[i][j]);
    int res = 0;
    if (m % 2) {
        int t = (m+1)/2;
        FOR(i, 1, n/2) res += a[t][i] != a[t][n-i+1];
    }
    if (n % 2) {
        int tmp = (n+1)/2;
        FOR(i, 1, m/2) res += a[i][tmp] != a[m-i+1][tmp];
    }
    //cerr << res << "\n";
    FOR(i, 1, m/2) FOR(j, 1, n/2) {
        int u = m-i+1;
        int v = n-j+1;
        res += 4 - mx(a[i][j], a[i][v], a[u][j], a[u][v]);
        //printf("%d %d %d %d\n", i, j, u, v);
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
