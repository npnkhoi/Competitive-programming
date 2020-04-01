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
const int N = 504;
const int md = 123456789;
int memo[2][N*N], s[2][N*N];
int main() {
    freopen("INVERSION.inp", "r", stdin);
    freopen("INVERSION.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    if (k > n*(n-1)/2) {
        printf("0\n");
        return 0;
    }

    int pre = 0, cur = 1;
    memo[cur][0] = 1;
    FOR(j, 0, k) s[cur][j] = 1;

    FOR(i, 2, n) {
        swap(pre, cur);
        memo[cur][0] = s[cur][0] = 1;
        FOR(j, 1, k) {
            if (j-i >= 0) memo[cur][j] = (s[pre][j] - s[pre][j-i] + md) % md;
            else memo[cur][j] = s[pre][j];
            s[cur][j] = (s[cur][j-1] + memo[cur][j]) % md;
            //printf("memo[%d][%d] = %d\n", i, j, memo[cur][j]);
        }
        //cerr << "\n";
    }
    printf("%d\n", memo[n%2][k]);
    return 0;
}
/** Happy Coding :D */
