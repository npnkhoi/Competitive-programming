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
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 3000 + 5;
int n, tmp;
ll k;
unsigned long long f[N][N];
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %lld", &n, &k);

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i-1][1];
        for (int j = 1; j <= n; j++)
        if (f[i-1][j-1] == -1 || f[i-1][j+1] == -1)
            f[i][j] = -1;
        else {
            f[i][j] = f[i-1][j-1] + f[i-1][j+1];
            if (f[i][j] >= k) f[i][j] = -1;
        }
    }

    tmp = 0;
    for (int i = 1; i <= n; i++) {
        ll w = f[n-i][tmp + 1];
        if (k <= w || w == -1)
            printf("("), tmp ++;
        else printf(")"), tmp --, k -= w;
    }
    return 0;
}
/** Happy Coding ^^ */

