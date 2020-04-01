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
const int N = 1e5 + 5;
ii a[N];
bool sign[N];
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    sort(a+1, a+n+1);

    int res = 0;
    for (int i = 1; i <= n; ++i) if (sign[a[i].se] == 0) {
        sign[a[i].se] = 1;
        sign[a[i].se - 1] = 1;
        sign[a[i].se + 1] = 1;
        ++ res;
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding ^^ */

