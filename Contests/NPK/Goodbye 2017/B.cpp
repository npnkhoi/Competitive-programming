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

const int N = 1e5 + 5;
vector< vector<long long> > f;
int n, m, w[N], v[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    f.assign(n+2, vector<long long>(m+2, 0));
    FOR(i, 1, n) scanf("%d %d", &w[i], &v[i]);
    FOR(i, 1, n) FOR(j, 1, m) {
        f[i][j] = f[i-1][j];
        if (w[i] <= j) f[i][j] = max(f[i][j], f[i-1][j-w[i]] + v[i]);
    }
    printf("%lld", f[n][m]);

}
/// Expelliarmus !
