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

const int N = 1e3 + 5;
const int M = 2e6 + 5;
int n;
ii a[N];
bool sign[M];
int res;

int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].se, &a[i].fi);
    res = 0;
    for (int i = 1; i <= n; i++) {
        int j = a[i].se;
        while (sign[j] == 1 || j <= res) j += a[i].fi;
        res = max(res, j);
        sign[j] = 1;
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding ^^ */

