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

int main() {
    freopen("TOURMAP.inp", "r", stdin);
    freopen("TOURMAP.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);

    if (m == n*(n-1)/2) {
        printf("Possible\n");
        FOR(i, 1, n-1)
        FOR(j, i+1, n) printf("%d %d\n", i, j);
    } else if (m == n) {
        printf("Possible\n");
        printf("1 %d\n", n);
        printf("1 2\n");
        FOR(i, 2, n-1) printf("%d %d\n", i, i+1);
    } else if (n%2 == 0 && m == n*n/4) {
        printf("Possible\n");
        FOR(i, 1, n/2)
        FOR(j, 1, n/2) printf("%d %d\n", i, n/2+j);
    } else printf("Impossible\n");

    return 0;
}
/** Happy Coding ^^ */
