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
const int N = 3e5 + 5;
const int oo = 1e9 + 7;
ii a[N];
int n, x, y;
int cntX, cntY, res;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].fi, &a[i].se);
    sort(a+1, a+n+1);
    //for (int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << "\n";
    cntX = 0; cntY = 0;
    res = oo;
    for (int l = 1, r = 1; r <= n; r++) {
        if (a[r].se == 1) cntX ++; else cntY ++;
        if (cntX >= x && cntY >= y) {
            while ((cntX > x && a[l].se == 1) || (cntY > y && a[l].se == 2)) {
                if (a[l].se == 1) cntX --; else cntY --;
                l++;
            }
            res = min(res, a[r].fi - a[l].fi);
        }
        //cout << l << " " << r << endl;
    }
    if (res == oo) printf("-1");
    else printf("%d\n", res);
    return 0;
}
/** Happy Coding ^^ */

