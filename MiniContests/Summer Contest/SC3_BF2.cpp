#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "SC3"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 500 + 5;

int tc, n, q, d;
vi que[N];
int a[N], b[N][N];

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d%d%d", &n, &q, &d);
        FOR(i, 1, n) {
            scanf("%d", &a[i]);
        }
        FOR(i, 1, n-d+1) {
            FOR(j, 1, d) b[i][j] = a[i+j-1];
            sort(b[i] + 1, b[i] + d + 1);
        }
        ll res = 0;
        while (q --) {
            int l, k;
            scanf("%d%d", &l, &k);
            //cerr << l << " " << k << "\n";
            res += b[l][d-k+1];
        }
        printf("%lld\n", res);
    }
}
