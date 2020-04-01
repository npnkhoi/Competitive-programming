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

const int N = 2e3 + 5;
const int oo = 1e9 + 7;
int n, posb[N], posw[N], f[N][N], b[N][N], w[N][N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, 2*n) {
        char ch;
        int x;
        scanf(" %c %d", &ch, &x);
        if (ch == 'B') posb[x] = i;
        else posw[x] = i;
    }


    FOR(i, 1, n) {
        FOR(j, 1, i-1) b[i][0] += (posb[j] > posb[i]);
        FOR(j, 1, n) b[i][j] = b[i][j-1] + (posw[j] > posb[i]);
    }
    /*FOR(i, 0, n) {
        FOR(j, 0, n) printf("%5d", b[i][j]);
        cerr << "\n";
    }+*/
    FOR(i, 1, n) {
        FOR(j, 1, i-1) w[i][0] += (posw[j] > posw[i]);
        FOR(j, 1, n) w[i][j] = w[i][j-1] + (posb[j] > posw[i]);
    }
    /*cerr << "\n"
    FOR(i, 0, n) {
        FOR(j, 0, n) printf("%5d", w[i][j]);
        cerr << "\n";
    }*/

    FOR(i, 0, n) FOR(j, 0 + (i == 0), n) {
        f[i][j] = oo;
        if (i) f[i][j] = min(f[i][j], f[i-1][j] + b[i][j]);
        if (j) f[i][j] = min(f[i][j], f[i][j-1] + w[j][i]);
    }
    printf("%d", f[n][n]);
}

