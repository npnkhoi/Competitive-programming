#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int M = 2500, N = 22;

int a[N];
bool dp[2][M+5][M+5];
int n;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    dp[0][0][0] = true;
    int cur = 0, nxt = 1;
    FOR(i, 1, n) {
        FOR(m1, 0, M) {
            FOR(m2, 0, M) {
                if (dp[cur][m1][m2]) {
                    dp[nxt][m1][m2] = true;
                    if (m1 + a[i] <= M) {
                        dp[nxt][m1+a[i]][m2] = true;
                    }
                    if (m2 + a[i] <= M) {
                        dp[nxt][m1][m2+a[i]] = true;
                    }
                }
            }
        }
        swap(cur, nxt);
    }
    int res = 0;
    FOR(i, 1, M) if (dp[cur][i][i]) res = i;
    cout << res;
}