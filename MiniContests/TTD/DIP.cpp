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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e5 + 5;
map<int, int> pos;
int n, q;
int a[N], f[N];

int main() {
    freopen("DIP.inp", "r", stdin);
    freopen("DIP.out", "w", stdout);
    scanf("%d%d", &n, &q);
    int l = 0;
    REP(r, n) {
        scanf("%d", &a[r]);
        if (pos.find(a[r]) != pos.end()) l = max(l, pos[a[r]] + 1);
        pos[a[r]] = r;
        f[r] = l;
    }
    //REP(j, n) cerr << f[j] << " ";
    REP(i, q) {
        int x, y;
        scanf("%d%d", &x, &y);
        int res = 0;
        FOR(j, x, y) res = max(res, j - max(x, f[j]) + 1);
        printf("%d\n", res);
    }

    return 0;
}
/** Happy Coding :D */
