#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "BTN"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105;
char str[N];
int n, k;
ll f[N][N][N], s[N][N][N];

int match(char a, char b) {
    if (a == '?' && b == '?') return 3;
    if (a == '(' && b == ')') return 1;
    if (a == '(' && b == '?') return 1;
    if (a == '?' && b == ')') return 1;
    if (a == '[' && b == ']') return 1;
    if (a == '?' && b == ']') return 1;
    if (a == '[' && b == '?') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '{' && b == '?') return 1;
    if (a == '?' && b == '}') return 1;
    return 0;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    scanf("%s", str+1);
    //cerr << "ok\n";
    FOR(i, 1, n+1) f[i][i-1][0] = s[i][i-1][0] = 1;
    FOR(x, 1, k) {
        FOR(i, 1, n+1) s[i][i-1][x] = 1;
        FOR(r, 1, n) {
            FORD(l, r, 1) {
                f[l][r][x] = match(str[l], str[r]) * f[l+1][r-1][x-1];
                //cerr << "f " << l << " " << r << " " << k << " " << f[l][r][k] << "\n";
                FOR(mid, l+1, r-2) {
                    f[l][r][x] += match(str[l], str[mid]) * (
                    f[l+1][mid-1][x-1] * s[mid+1][r][x] +
                    s[l+1][mid-1][x-1] * f[mid+1][r][x] -
                    f[l+1][mid-1][x-1] * f[mid+1][r][x]);
                    //cerr << "upgrade " << f[l][r][x] << "\n";/
                }

                s[l][r][x] = s[l][r][x-1] + f[l][r][x];
                /*cerr << "f " << l << " " << r << " " << x << " " << f[l][r][x] << "\n";
                cerr << "s " << l << " " << r << " " << x << " " << s[l][r][x] << "\n";*/
            }
        }
    }
    //cerr << match(str[1], str[4]);
    printf("%lld", f[1][n][k]);
}
