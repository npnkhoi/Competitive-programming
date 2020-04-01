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
#define FORD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 25;
int a[N][N], d[N];
int m, n, s;
bool ok(int x) {
    if (s%x) return 0;
    FOR(i, 1, s) if (d[i] != d[(i+x)%s]) return 0;
    return 1;
}
int main() {
    freopen("SCTAB.inp", "r", stdin);
    freopen("SCTAB.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &s);
    FOR(i, 1, m) FOR(j, 1, n) scanf("%d", &a[i][j]);
    int num;
    FOR(i, 1, s) {
        scanf("%d", &d[i]);
    }
    d[0] = d[s];
    FOR(j, 1, s) if (ok(j)) {
        cout << j << endl;
        FOR(k, 1, j) cout << d[k] << endl;
        return 0;
    }
    return 0;
}
/** Happy Coding ^^ */

