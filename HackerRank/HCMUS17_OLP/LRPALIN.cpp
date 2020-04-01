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
const int N = 1e4 + 2;
char s[N];
int f[N][N];
int n, q, l, r;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%s", s+1); n = strlen(s+1);
    f[1][1] = 1;
    for (int j = 2; j <= n; j++) {
        f[j][j] = 1;
        f[j-1][j] = (s[j-1] == s[j]);
        for (int i = j-2; i >= 1; i--) f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", f[l][r]);
    }
    return 0;
}
/** Happy Coding ^^ */

