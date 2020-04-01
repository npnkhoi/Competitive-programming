using namespace std;
#include <stdio.h>
#include <string.h>
#include <iostream>
const int N = 55;
const int S = 205;
const int K = 2005;
int a[N], x[N], y[N], d[N];
bool dp[N][S][K];
int n, s, k;
void trace(int i, int j, int l) {
    if (i == n && j == s && l == k) return;
    if (dp[i+1][j][l]) trace(i+1, j, l);
    else {
        d[i] ++;
        trace(i, j+x[i], l + y[i]);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &n, &s, &k);
        //-------------------
        for (int i = 0; i < n; i++) x[i] = n-i;
        int tmp = 1-n; memset(y, 0, sizeof y);
        for (int i = 0; i < n; i++, tmp += 2) {
            y[0] += tmp;
            y[i+1] -= tmp;
        }
        tmp = 0;
        for (int i = 1; i < n; i++) y[i] += y[i-1];
        //---------------------------------
        memset(dp, 0, sizeof dp);
        dp[n][s][k] = 1;
        for (int i = n-1; i >= 0; i--)
        for (int j = s; j >= 0; j--)
        for (int l = k; l >= 0; l--) {
            if (j + x[i] <= s && 0 <= l + y[i] && l + y[i] <= k)
                dp[i][j][l] = dp[i+1][j][l] | dp[i][j + x[i]][l + y[i]];
            else dp[i][j][l] = dp[i+1][j][l];
        }
        //cout << "ok\n";
        if (dp[0][0][0]) {
            memset(d, 0, sizeof d);
            trace(0, 0, 0);
            int tmp = 0;
            for (int i = 0; i < n; i++) printf("%d ", tmp = tmp + d[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
}
