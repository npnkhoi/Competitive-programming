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
const int N = 6e3 + 3;
ii a[N], b[N];
int f[N][N];
bool sign1[N], sign2[N];
vector<int> ans1, ans2, ans3, ans4;
int n, ans[N];

void trace(int i, int j) {
    //printf("trace %d %d\n", i, j);
    if (i == 0 || j == 0) return;
    if (f[i][j] == f[i-1][j]) trace(i-1, j);
    else if (f[i][j] == f[i][j-1]) trace(i, j-1);
    else {
        ans1.push_back(a[i].se);
        sign1[a[i].se] = 1;
        ans2.push_back(b[j].se);
        sign2[b[j].se] = 1;
        trace(i-1, j-1);
    }
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i].fi);
        b[i].se = i;
    }
    sort(b+1, b+n+1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if (a[i].fi >= b[j].fi) {
                int tmp = (a[i].fi > b[j].fi) ? 2 : 1;
                f[i][j] = max(f[i][j], tmp + f[i-1][j-1]);
            }
            //printf("%3d", f[i][j]);
        }
        //cout << "\n";
    }
    //printf("%d\n", f[n][n] - n);
    trace(n, n);
    for (int i = 1; i <= n; i++) if (sign1[i] == 0) ans3.push_back(i);
    for (int i = 1; i <= n; i++) if (sign2[i] == 0) ans4.push_back(i);
    for (int i = 0; i < ans1.size(); i++) printf("%d %d\n", ans1[i], ans2[i]);
    for (int i = 0; i < ans3.size(); i++) printf("%d %d\n", ans3[i], ans4[i]);
    return 0;
}
/** Happy Coding ^^ */

