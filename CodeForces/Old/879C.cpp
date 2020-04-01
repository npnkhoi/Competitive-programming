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
const int N = 5e5 + 5;
pair<char, int> a[N];
int n;
int res[12][5];
int ans(int num) {
    int res = num;
    for (int i = 1; i <= n; ++i)
        if (a[i].fi == '|') res = res | a[i].se;
        else if (a[i].fi == '&') res = res & a[i].se;
        else res = res ^ a[i].se;
    return res;
}
int sum(int z) {
    int s = 0;
    for (int i = 0; i <= 9; i++) s += res[i][z] << i;
    return s;
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf(" %c %d", &a[i].fi, &a[i].se);
    for (int z = 9; z >= 0; z--) {
        int u = (ans(0<<z) >> z) % 2;
        int v = (ans(1<<z) >> z) % 2;

        if (u == 1 && v == 1)
            res[z][3] = 1;
        else if (u == 1 && v == 0)
            res[z][2] = res[z][1] = 1;
        else if (u == 0 && v == 1)
            res[z][2] = 1;
    }
    printf("3\n");
    printf("^ %d\n", sum(1));
    printf("& %d\n", sum(2));
    printf("| %d\n", sum(3));
    return 0;
}
/** Happy Coding ^^ */

