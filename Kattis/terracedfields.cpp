#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < n; i++)
const int D = 20;
const int R = 8;
long long f[D][D][R], g[D][D][R][2];
char s[20];
int q;
long long res;
vector<int> pre[10];

void prepare() {
    FOR(i, 0, 7) pre[10*i % 8].push_back(i);
}
void calcF() {
    f[0][0][0] = 1;
    FOR(i, 1, 18)
    FOR(c, 0, i)
    FOR(r, 0, 7)
    FOR(d, 0 + (i == 1), 9) if (c - (d == 6 | d == 8) >= 0) {
        int tmp = (r - d + 16) % 8;
        REP(j, pre[tmp].size())
        f[i][c][r] += f[i-1][c - (d == 6 | d == 8)][pre[tmp][j]];
        //printf("f(%d, %d, %d)(%d) = %lld\n", i, c, r, d, f[i][c][r]);
    }
//    FOR(i, 1, 2) FOR(c, 0, i) FOR(r, 0, 7)
//        printf("f(%d, %d, %d) = %lld\n", i, c, r, f[i][c][r]);
}
long long ans(long long n) {
    long long res = 0;
    for (long long i = 8; i <= n - n%8; i += 8) {
        int tmp = i;
        while (tmp > 0) {
            res += (tmp % 10 == 8 | tmp % 10 == 6);
            //if (tmp % 10 == 8 | tmp % 10 == 6) cerr << i << '\n';
            tmp /= 10;
        }
    }
    return res;
}
long long val(char s[]) {
    int n = strlen(s+1);
    long long res = 0;
    FOR(i, 1, n) res = res * 10 + s[i] - '0';
    return res;
}
int main() {
    prepare();
    calcF();
    scanf("%d", &q);
    while (q--) {
        res = 0;
        scanf("%s", s + 1);
        //printf("%s\n", s + 1);
        int m = strlen(s + 1);
        FOR(i, 1, m-1) FOR(c, 1, i) res += c * f[i][c][0];
        //cerr << "res f " << res << ' ';

        memset(g, 0, sizeof g);
        g[0][0][0][0] = 1;
        FOR(i, 1, m)
        FOR(c, 0, i)
        FOR(r, 0, 7) {
            if (c - (s[i] == '6' || s[i] == '8') >= 0) {
                int tmp = (r - (s[i] - '0') + 16) % 8;
                REP(j, pre[tmp].size())
                g[i][c][r][0] += g[i-1][c - (s[i] == '6' | s[i] == '8')][pre[tmp][j]][0];
            }

            FOR(d, 0 + (i == 1), s[i] - '0' - 1) if (c - (d == 6 | d == 8) >= 0) {
                int tmp = (r - d + 16) % 8;
                REP(j, pre[tmp].size())
                g[i][c][r][1] += g[i-1][c - (d == 6 | d == 8)][pre[tmp][j]][0];
            }
            FOR(d, 0 + (i == 1), 9) if (c - (d == 6 | d == 8) >= 0) {
                int tmp = (r - d + 16) % 8;
                REP(j, pre[tmp].size())
                g[i][c][r][1] += g[i-1][c - (d == 6 | d == 8)][pre[tmp][j]][1];
            }
            //printf("f(%d, %d, %d) = %lld, %lld\n", i, c, r, g[i][c][r][0], g[i][c][r][1]);
        }
        FOR(c, 1, 18) res += c * (g[m][c][0][0] + g[m][c][0][1]);

        //cerr << ans(val(s)) << ' ' << res << '\n';
        if (val(s) % 8) {
            FOR(i, 1, m) res += (s[i] == '6' | s[i] == '8');
        }
        cout << res << '\n';
    }
}
