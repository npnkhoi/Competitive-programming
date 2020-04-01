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
const int N = 55;
const int MASK = (1<<5) + 5;
int n, k, ans[N];
pll t, dp[N][N][MASK];
string s;

bool operator < (pll &a, pll &b) {
    if (a.fi != b.fi) return a.fi < b.fi;
    else return a.se < b.se;
}
pll operator + (pll &a, pll &b) {
    pll c;
    c.fi = a.fi + b.fi;
    c.se = a.se + b.se;
    if (c.se >= base) {
        c.se -= base;
        c.fi += 1;
    }
    return c;
}
pll operator - (pll &a, pll &b) {
    pll c;
    c.fi = a.fi - b.fi;
    c.se = a.se - b.se;
    if (c.se < 0) {
        c.se += base;
        c.fi -= 1;
    }
    return c;
}
bool ok(int mask) {
    return __builtin_popcount(mask) <= 1;
}
int main() {
    freopen("qpalin.inp", "r", stdin);
    freopen("qpalin.out", "w", stdout);
    scanf("%d%d ", &n, &k); k += 2;

    getline(cin, s);
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); ++i)
        while (s[i] == s[i-1] && i < s.size()) s.erase(s.begin() + i);
    //cerr << s << endl;
    int m = s.size();

    scanf("%lld", &t);
    ll oo = t + 1;

    FORD(i, n, 1) FORD(j, n, 0) REP(mask, 1<<m) {
        if (i == n) dp[i][j][mask].se = (j >= k && ok(mask));
        else {
            REP(x, m) {
                dp[i][j][mask] += dp[i+1][j + ok(mask^(1<<x))][mask^(1<<x)];
                if (dp[i][j][mask] > t) {
                    dp[i][j][mask] = oo;
                    break;
                }
            }
        }
        //printf("dp[%d][%d][%d] = %lld\n", i, j, mask, dp[i][j][mask]);
    }

    int j = 0, mask = 0;
    FOR(i, 1, n) {
        ll tmp = 0;
        REP(x, m) {
            int u = j + ok(mask^(1<<x));
            int v = mask^(1<<x);
            tmp += dp[i][u][v];
            //printf("%d %d %d: %lld\n", i, u, v, dp[i][u][v]);
            if (tmp >= t) {
                tmp -= dp[i][u][v];
                t -= tmp;
                j = u, mask = v;
                printf("%c", s[x]);
                break;
            }
        }
    }
    return 0;
}
