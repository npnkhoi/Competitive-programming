#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105;
char a[6][N];
int f[6][N], g[6][N];
int n;
int main() {
    freopen("0.inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, 4) FOR(j, 1, n) scanf(" %c", &a[i][j]);
    FOR(i, 1, 4) f[i][1] = 1;
    FOR(j, 1, n) f[1][j] = 1;
    FOR(i, 2, 4) FOR(j, 2, n) if (a[i][j] == '.') f[i][j] = f[i-1][j] + f[i][j-1];

    FOR(i, 1, 4) g[i][1] = 1;
    FOR(j, 1, n) g[4][j] = 1;
    FORD(i, 3, 1) FOR(j, 2, n) if (a[i][j] == '.') g[i][j] = g[i+1][j] + g[i][j-1];

    FOR(i, 1, 4) {
        FOR(j, 1, n) printf("%5d", f[i][j]);
        cout << "\n";
    }

    cout << "ok\n";
    FOR(i, 1, 4) {
        FOR(j, 1, n) printf("%5d", g[i][j]);
        cout << "\n";
    }
    cout << "ok\n";

}
