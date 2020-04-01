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

const int M = 105;
const int N = 10000;
int m;
ll a, b;
ii p[M];
int memo[N+3][M];
ll fn(int num, int pos) {
    if (pos == 0) return num >= 1;
    else if (num == 0) return 0;
    else if (num <= N && memo[num][pos] != -1)
        return memo[num][pos];
    else {
        int s = 0;
        ll t = 1;
        for (int i = 0; t <= num && i <= p[pos].se; ++i) {
            s += fn(num / t, pos-1);
            t = t * p[pos].fi;
        }
        if (num <= N) memo[num][pos] = s;
        return s;
    }
}
int main() {
    freopen("USAB.inp", "r", stdin);
    freopen("USAB.out", "w", stdout);
    memset(memo, -1, sizeof memo);
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) scanf("%d%d", &p[i].fi, &p[i].se);
    sort(p+1, p+m+1);

    REP(z, 3) {
        scanf("%d%d", &a, &b);
        printf("%d\n", fn(b, m) - fn(a-1, m));
        //cout << fn(b, n) << " " << fn(a-1, n) << endl;
    }
}
/** Happy Coding ^^ */

