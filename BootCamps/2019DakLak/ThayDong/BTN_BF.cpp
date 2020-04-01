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
    FOR(i, 1, n+1) s[i][i-1][0] = 1;
    FOR(x, 1, k) {
        FOR(i, 1, n+1) s[i][i-1][x] = 1;
        FOR(r, 1, n) {
            FORD(l, r, 1) {
                s[l][r][x] = match(str[l], str[r]) * s[l+1][r-1][x-1];
                FOR(mid, l+1, r-2) {
                    s[l][r][x] += match(str[l], str[mid]) * s[l+1][mid-1][x-1] * s[mid+1][r][x];
                }
                //cerr << "s " << l << " " << r << " " << x << " " << s[l][r][x] <<  "\n";
            }
        }
    }
    printf("%lld", s[1][n][k] - s[1][n][k-1]);
}
