#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "BONUS"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 505;
int n, r, k;
int a[N][N], mark[N][N];
long long res;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d%d", &n, &r, &k);
    FOR(i, 1, n) {
        FOR(j, 1, n) scanf("%d", &a[i][j]);
    }
    FOR(z, 1, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        FOR(i, x, x+r-1) FOR(j, y, y+r-1) mark[i][j] = 1;
    }
    FOR(i, 1, n) FOR(j, 1, n) if (mark[i][j]) res += a[i][j];
    printf("%lld", res);
}
