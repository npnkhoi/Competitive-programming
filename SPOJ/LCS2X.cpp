#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 1500 + 5;
int tc, m, n, a[N], b[N], memo[N], ans, res, tmp;
int main() {
    scanf("%d", &tc);
    REP(z, tc) {
        memset(memo, 0, sizeof memo);
        res = 0;
        scanf("%d %d", &m, &n);
        FOR(i, 1, m) scanf("%d", &a[i]);
        FOR(i, 1, n) scanf("%d", &b[i]);

        FOR(i, 1, m) {
            tmp = 0;
            FOR(j, 1, n) {
                if (a[i] == b[j]) {
                    ans = 1 + tmp;
                    res = max(res, ans);
                }
                if (a[i] >= 2*b[j]) tmp = max(tmp, memo[j]);
                if (a[i] == b[j]) memo[j] = max(memo[j], ans);
            }
        }
        printf("%d\n", res);
    }
}
