#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define taskName "0"

const int N = 18;
const int MAX_COST = N*N;
const int oo = MAX_COST + 5;
char type[N];
int n, r[N], b[N];
int tmp[MAX_COST];
int saveR, saveB;
vector<ii> dp[1 << N];
bool onbit(int mask, int i) {
    return (mask & (1 << i)) > 0;
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    REP(i, n) {
        scanf(" %c%d%d", &type[i], &r[i], &b[i]);
        if (r[i] > n) {
            saveR += r[i] - n;
            r[i] = n;
        }
        if (b[i] > n) {
            saveB += b[i] - n;
            b[i] = n;
        }
    }
    dp[0].pb(mp(0, 0));
    int nbit = (1 << n) - 1;
    FOR(mask, 1, nbit) {
        //printf("dp[%d]: \n", mask);
        FOR(i, 0, MAX_COST) tmp[i] = oo;

        int curR = 0, curB = 0;
        REP(i, n) if (onbit(mask, i)) {
            if (type[i] == 'R') curR ++;
            else curB ++;
        }
        //printf("cur RB: %d %d\n",curR, curB);

        REP(last, n) if (onbit(mask, last)) {
            int pre = mask ^ (1 << last);
            //printf("-> %d\n", pre);
            int costR = max(r[last] - (curR - (type[last] == 'R')), 0);
            int costB = max(b[last] - (curB - (type[last] == 'B')), 0);
            REP(i, dp[pre].size()) {
                ii t = dp[pre][i];
                tmp[t.fi + costR] = min(tmp[t.fi + costR], t.se + costB);
            }
        }
        int minTmp = oo;
        FOR(i, 0, MAX_COST) if (tmp[i] < oo) {
            dp[mask].pb(mp(i, tmp[i]));
            minTmp = min(minTmp, tmp[i]);
        }
        //cerr << "--------\n";
    }
    int res = (int)2e9 + 7;
    REP(i, dp[nbit].size()) {
        ii t = dp[nbit][i];
        res = min(res, max(t.fi + saveR, t.se + saveB));
    }
    res += n;

    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
