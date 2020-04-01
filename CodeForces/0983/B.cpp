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

const int N = 5005;
int n, q, a[N], f[N][N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);

    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(l, 1, n) FOR(i, 1, n-l+1) {
        int j = i + l - 1;
        if (l == 1) f[i][j] = a[i];
        else f[i][j] = f[i+1][j] ^ f[i][j-1];
    }
    FOR(l, 1, n) FOR(i, 1, n-l+1) {
        int j = i + l - 1;
        if (l > 1) f[i][j] = max(f[i][j], max(f[i+1][j], f[i][j-1]));
    }
    scanf("%d", &q);
    FOR(i, 1, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", f[l][r]);
    }
}
