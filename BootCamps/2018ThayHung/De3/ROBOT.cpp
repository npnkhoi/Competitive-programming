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
#define task "robot"
const int N = 1e6 + 5;
char s[N];

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int n, x, y;
    scanf("%d", &n);
    scanf("%s", s+1);
    scanf("%d%d", &x, &y);
    x = -x; y = -y;
    int l = 0, r = 0, u = 0, d = 0;

    FOR(i, 1, n) {
        switch(s[i]) {
            case 'L': {
                if (x > 0) {
                    -- x;
                    if (x == 0) l = i;
                }
                break;
            }
            case 'R': {
                if (x < 0) {
                    ++ x;
                    if (x == 0) r = i;
                }
                break;
            }
            case 'U': {
                if (y < 0) {
                    ++ y;
                    if (y == 0) u = i;
                }
                break;
            }
            case 'D': {
                if (y > 0) {
                    -- y;
                    if (y == 0) d = i;
                }
                break;
            }
        }
        if (x == y && y == 0) break;
    }
    if (x == 0 && y == 0) printf("%d %d %d %d\n", l, u, r, d);
    else printf("-1\n");

    return 0;
}
/** Happy Coding ^^ */

