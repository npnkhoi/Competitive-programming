using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FOD(i,b,a) for (int i = (b); i >= (a); --i)
#define REP(i,n) for (int i = 0; i < (n); ++i)

const int N = 105;
const int oo = 1e9 + 7;

int n, l;
int w[N], f[N], c[N];
int g[N][N][N][N];
string str, s[N];
set<int> data;
map<string, int> w2;
int memo[N][N];
int id(int i, int j) {
    return 26*(str[i]-'a') + (str[j] - 'a');
}
int dp1(int i, int j) {
    if (i > j) return 0;
    else if (i == j) return -oo;
    else if (memo[i][j] != -1) return memo[i][j];
    else {
        int res = -oo;
        FOR(k, i, j-1) res = max(res, dp1(i, k) + dp1(k+1, j));
        if (w[id(i, j)] > 0) res = max(res, w[id(i, j)] + dp1(i+1, j-1));
        return memo[i][j] = res;
    }
}
void sub1() {
    FOR(i, 1, n) {
        w[26*(s[i][0]-'a') + s[i][1] - 'a'] = c[i];
    }
    f[0] = 0;
    FOR(i, 1, l-1) {
        f[i] = max(f[i-1], dp1(0, i));
        FOR(j, 1, i) f[i] = max(f[i], f[j-1] + dp1(j, i));
    }
    cout << f[l-1];
}
int score(int i, int j, int k) {
    string t = "";
    t += str[i];
    t += str[j];
    t += str[k];
    return w2[t];
}
int dp2(int i, int j) {
    if (i > j) return 0;
    else if (j-i+1 <= 2) return -oo;
    else if (memo[i][j] != -1) return memo[i][j];
    else {
        int res = -oo;
        FOR(k, i, j-2) res = max(res, dp2(i, k) + dp2(k+1, j));
        FOR(k, i+1, j-1) if (score(i, k, j) > 0)
            res = max(res, score(i, k, j) + dp2(i+1, k-1) + dp2(k+1, j-1));
        return memo[i][j] = res;
    }
}
void sub2() {
    FOR(i, 1, n) w2[s[i]] = c[i];
    f[0] = 0;
    FOR(i, 1, l-1) {
        f[i] = max(f[i-1], dp2(0, i));
        FOR(j, 1, i) f[i] = max(f[i], f[j-1] + dp2(j, i));
    }
    cout << f[l-1];
}
int dp3_f(int i, int j) {
    if (i > j) return 0;
    else return memo[i][j];
}
int dp3_g(int i, int j, int k, int h) {
    if (i > j)
        if (h < 0) return 0;
        else return -oo;
    else if (h < 0) return -oo;
    else return g[i][j][k][h];
}
void sub3() {
    REP(i, l) REP(j, l) memo[i][j] = -oo;
    REP(i, l) REP(j, l) FOR(k, 1, n) REP(h, (int)s[k].size())
        g[i][j][k][h] = -oo;

    FOD(i, l-1, 0)
    FOR(j, i, l-1)
    FOR(k, 1, n) {
        REP(h, min(j-i+1, (int) s[k].size())) {
            if (str[j] == s[k][h]) {
                FOR(j_, i, j) {
                    g[i][j][k][h] = max(g[i][j][k][h],
                    dp3_g(i, j_-1, k, h-1) + dp3_f(j_, j-1));
                }
            }
        }
        memo[i][j] = max(memo[i][j], g[i][j][k][s[k].size() - 1] + c[k]);
    }
    FOR(i, 0, l-1) {
        if (i > 0) f[i] = max(0, max(f[i-1], memo[0][i]));
        else f[i] = max(0, memo[0][i]);
        FOR(j, 1, i) f[i] = max(f[i], f[j-1] + memo[j][i]);
    }
    cout << f[l-1];

}
int main() {
    freopen("WORD.inp", "r", stdin);
    freopen("WORD.out", "w", stdout);
    memset(memo, -1, sizeof memo);
    getline(cin, str); l = str.size();
    scanf("%d ", &n);

    FOR(i, 1, n) {
        getline(cin, s[i]);
        //data.insert((int)s[i].size());
        scanf("%d ", &c[i]);
    }
    /*if (data.size() == 1 && s[1].size() == 2) sub1();
    else if (data.size() == 1 && s[1].size() == 3) sub2();
    else if (*data.rbegin() <= 5) */
    sub3() ;
    return 0;
}
/** Happy Coding ^^ */

