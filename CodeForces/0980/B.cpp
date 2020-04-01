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

int n, k;
int a[5][105];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    if (k % 2 == 0) {
        FOR(i, 1, k/2) a[2][1+i] = a[3][i+1] = 1;
    } else {
        if (k <= n-2) {
            FOR(j, (n-k)/2 + 1, n - (n-k)/2) a[2][j] = 1;
        } else {
            FOR(j, 2, n-1) a[2][j] = 1;
            a[3][2] = a[3][n-1] = 1;
            REP(j, k-n) a[3][3 + j] = 1;
        }
    }
    printf("YES\n");
    FOR(i, 1, 4) {
        FOR(j, 1, n) if (a[i][j]) printf("#");
        else printf(".");
        printf("\n");
    }
}
