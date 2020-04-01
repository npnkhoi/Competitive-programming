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
const int A = 3e4 + 5;
int cnt[A];
int main() {
    freopen("TV1.inp", "r", stdin);
    freopen("TV1.out", "w", stdout);
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        ++ cnt[x];
        scanf("%d", &x);
        -- cnt[x-1];
    }
    int res = 0;
    int cur = 0;
    for (int i = 1; i <= 3e4; ++i)
        cur += cnt[i], res = max(res, cur);
    printf("%d\n", res);
    return 0;
}
/** Happy Coding ^^ */

