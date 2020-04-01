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
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int A = 1e6 + 5;
int cnt[A];
int main() {
    freopen("TV1.inp", "r", stdin);
    freopen("TV1.out", "w", stdout);
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        ++ cnt[x];
        -- cnt[y];
    }
    int res = 0;
    int cur = 0;
    for (int i = 0; i <= 1e6; ++i)
        cur += cnt[i], res = max(res, cur);
    printf("%d\n", res);
    return 0;
}
/** Happy Coding ^^ */

