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
const int N = 5e4 + 5;
int x[N], l[N], r[N];
double res;
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int m, n;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &x[i]);
    sort(x+1, x+m+1);
    n = 1;
    for (int i = 2; i <= m; i++) if (x[i] != x[i-1]) x[++n] = x[i];
    //for (int i = 1; i <= n; i++) cout << x[i] << endl;
    if (n == 1) { printf("1.0"); return 0; }

    l[1] = 0;
    for (int i = 2; i <= n; i++) l[i] = 1.0 + max(l[i-1], x[i] - x[i-1]);
    r[n] = 0;
    for (int i = n-1; i >= 1; i--) r[i] = 1.0 + max(r[i+1], x[i+1] - x[i]);

    res = min(r[1], l[n]);
    for (int i = 1; i < n; i++) {
        double tmp = max(1.0*max(l[i], r[i+1]), 0.5*(x[i+1]-x[i]));
        res = min(res, tmp);
        //printf("%d %d %f\n", l[i], r[i+1], res);
    }
    printf("%.1f", res);

    return 0;
}
/** Happy Coding ^^ */

