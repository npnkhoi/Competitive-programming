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

const int N = 20;
const int A = 30;
const int oo = 1e9 + 7;
string str;
int n, a[N][A], memo[1<<N], tmp[A];

int tinh(int mask) {
    REP(i, 26) tmp[i] = oo;
    REP(i, n) if (mask & (1<<i)) {
        REP(j, 26) tmp[j] = min(tmp[j], a[i][j]);
    }
    int s = 0;
    REP(i, 26) s += tmp[i];
    return s;
}
int dp(int mask) {
    //cout << "dp " << mask << "\n";
    if (memo[mask] != -1) return memo[mask];
    else if (__builtin_popcount(mask) == 1) {
        int s = 0;
        int x = int(log2(mask));
        REP(i, 26) s += a[x][i];
        return memo[mask] = s;
    } else {
        vector<int> pos;
        for (int i = 0; 1 << i <= mask; i++)
        if (mask & (1<<i)) pos.push_back(i);
        int m = pos.size();
        //REP(j, m) cerr << pos[j] << " "; cerr << "\n";
        int res = oo;
        FOR(maskTmp, 1, (1<<m) - 2) {
            int mask1 = 0, mask2 = 0;
            REP(j, m) if ((1<<j)&maskTmp) mask1 |= (1 << pos[j]);
            else mask2 |= (1 << pos[j]);
            res = min(res, dp(mask1) + dp(mask2));
        }
        return memo[mask] = res - tinh(mask);
    }

}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("F.inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d ", &n);
    REP(i, n) {
        getline(cin, str);
        REP(j, str.size()) {
            a[i][str[j] - 'a'] ++;
        }
        /*REP(j, 26) cerr << a[i][j] << " ";
        cerr << "\n";*/
    }
    memset(memo, -1, sizeof memo);
    memo[0] = 0;
    //REP(i, 1<<n) printf("%d: %d\n", i, dp(i));

    printf("%d\n", 1 + dp((1<<n) - 1));
    return 0;
}
/** Happy Coding :D */
