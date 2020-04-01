#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "A"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2000;
int n, mark[N], a[N][N];
void calc(int x, int y) {
    memset(mark, 0, sizeof mark);
    FOR(j, 1, y) mark[a[x][j]] = 1;
    FOR(i, 1, x) mark[a[i][y]] = 1;
    FOR(i, 1, 2*n) if (mark[i] == 0) {
        a[x][y] = i;
        return;
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    n = 200;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            calc(i, j);
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}
/// Expelliarmus !
