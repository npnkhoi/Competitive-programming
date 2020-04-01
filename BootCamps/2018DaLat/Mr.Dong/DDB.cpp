using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int maxN = 2e6 + 5;
bool vis[maxN + 2];
int s[maxN + 2], ans[maxN + 2];
int n, x;

int main() {
    freopen("DDB.inp", "r", stdin);
    freopen("DDB.out", "w", stdout);
    vis[0] = vis[1] = 1;
    FOR(i, 2, maxN) if (vis[i] == 0) {
        for (ll j = 1LL*i*i; j <= maxN; j += i)
            vis[j] = 1;
    }
    FOR(i, 2, maxN) {
        s[i] = s[i-1] + (vis[i] == 0);
        if (i%2 == 0) {
            ans[i>>1] = s[i] - s[i>>1];
            cerr << i << " " << ans[i >> 1] << "\n";
        }
        //if (vis[i] == 0) cerr << i << "\n";
    }

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}
/** Happy Coding ^^ */

