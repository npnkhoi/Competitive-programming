using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 2000 + 5;
const int oo = 1e9 + 7;
int n, mid, a[N], f[N][N];
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d", &n);
    mid = (n+1)/2;

    int cnt = 0;
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        if (a[i] == 1) cnt ++;
    }
    if (cnt > 0) {
        printf("%d\n", n-cnt);
        return 0;
    }
    int res = oo;
    FORD(i, n, 1) FOR(j, i, n) {
        if (i == j) f[i][j] = a[i];
        else f[i][j] = __gcd(f[i][j-1], a[j]);
        if (f[i][j] == 1) res = min(res, j-i+n-1);
    }
    if (res == oo) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
