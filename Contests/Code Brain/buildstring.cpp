using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define For(i, a, b) for (int i = a; i <= b; i++)
#define F0r(i, b, a) for (int i = b; i >= a; i--)

typedef pair<int, int> ii;
typedef vector<int> vi;

using namespace std;
const int N = 55;
const int md = 1e9 + 7;
long long f[N][N][N];
int main()
{
    int n, m;
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) f[i][0][0] = 1;

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
    for (int k = 0; k <= m; k++) {
        f[i][j][k] = f[i-1][j-1][k];
        if (k >= j && i > j) f[i][j][k] = (f[i][j][k] + f[i-1][j][k-j]) % md;
    }
    long long res = 0;
    for (int j = 0; j <= n; j++) res = (res + f[n][j][m]) % md;
    cout << res;
    return 0;
}
/**/

