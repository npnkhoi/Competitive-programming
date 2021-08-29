#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "SC1"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
int tc, n, d[N];
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d", &n);
        int cnt = 0;
        FOR(i, 1, n) {
            scanf("%d", &d[i]);
            if (d[i] == 0) cnt ++;
        }
        if (d[1] == 0 && cnt == 1) {
            printf("%d\n", n-1);
            FOR(i, 2, n) printf("1 %d %d\n", i, d[i]);
        } else printf("-1\n");
    }
}
