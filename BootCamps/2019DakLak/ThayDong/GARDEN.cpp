#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "garden"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;
char s[N];
int f[N][5][5][5], n, m;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    FOR(c, 0, 4) FOR(minc, 0, c) FOR(maxc, c, 4) if (maxc - minc <= 2)
        f[n+1][c][minc][maxc] = 1;
    FORD(i, n, 1) FOR(c, 0, 4) FOR(minc, 0, c) FOR(maxc, c, 4) if (maxc - minc <= 2) {
        if (c > 0) f[i][c][minc][maxc] = (f[i][c][minc][maxc] + f[i+1][c-1][min(minc, c-1)][maxc]) % m;
        if (c < 4) f[i][c][minc][maxc] = (f[i][c][minc][maxc] + f[i+1][c+1][minc][max(maxc, c+1)]) % m;
        //cerr << i << " " << c << " " << minc << " " << maxc << " " << f[i][c][minc][maxc] << "\n";
    }
    int res = 1, c = 2, minc = 2, maxc = 2;
    FOR(i, 1, n) {
        if (s[i] == 'P' && c < 4) res = (res + f[i+1][c+1][minc][max(maxc, c+1)]) % m;
        if (s[i] == 'P') c--; else c ++;
        minc = min(minc, c);
        maxc = max(maxc, c);
    }
    printf("%d", res);
}
