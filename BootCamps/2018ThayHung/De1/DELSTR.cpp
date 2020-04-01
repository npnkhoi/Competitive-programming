#include <utility>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < n; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)

#define task "DELSTR"

const int N = 1005;
const int oo = 1005;
char s[N];
int m, n, f[N][N], g[N][N];
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &m);
    n = 0;
    REP(i, m) {
        char ch;
        scanf(" %c", &ch);
        if (n == 0 || ch != s[n]) s[++n] = ch;
    }
    //printf("%s\n", s+1);
    FORD(l, n, 1) FOR(r, l, n) {
        if (l == r) {
            f[l][r] = 1;
            g[l][r] = 0;
        } else {
            f[l][r] = g[l][r] = oo;

            FOR(k, l, r-1) f[l][r] = min(f[l][r], f[l][k] + f[k+1][r]);
            if (s[l] == s[r]) {
                //printf("into\n");
                FOR(k, l, r-1) {
                    g[l][r] = min(g[l][r], g[l][k] + f[k+1][r-1]);
                    //printf("%d + %d\n", g[l][k], f[k+1][r-1]);
                }
                f[l][r] = min(f[l][r], g[l][r] + 1);
            }
        }
        //printf("f(%d, %d) = %d\n", l, r, f[l][r]);
        //printf("g(%d, %d) = %d\n", l, r, g[l][r]);
    }
    printf("%d", f[1][n]);

    return 0;
}
