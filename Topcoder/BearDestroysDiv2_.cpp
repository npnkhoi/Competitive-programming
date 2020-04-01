#include <cstdio>
#include <iostream>
using namespace std;

const int W = 9;
const int H = 42;
int w, h, md, dp[H][W][2 << W], EXP[W*H];

class BearDestroysDiv2 {
    public:
    int sumUp(int w, int h, int md) {
        EXP[0] = 1;
        for (int i = 1; i <= w * h; i ++) {
            EXP[i] = (EXP[i-1] * 2) % md;
        }
        dp[h+1][1][0] = 0;
        for (int i = h; i >= 1; i --)
        for (int j = w; j >= 1; j --)
        for (int mask = 0; mask < (1 << w); mask ++) {
            int u, v;
            if (j == w) u = i+1, v = 1;
            else u = i, v = j+1;
            int f0 = dp[u][v][mask >> 1];
            int fs = (dp[u][v][(mask >> 1) + (1 << (w-1))] + EXP[w * h - (i-1) * w - j]) % md;
            int fe = (dp[u][v][(mask >> 1) | 1] + EXP[w * h - (i-1) * w - j]) % md;

            // South
            if (i < h && ((mask & 1) == 0))
                dp[i][j][mask] = (dp[i][j][mask] + fs) % md;
            else if (j < w && ((mask & 3) == 0))
                dp[i][j][mask] = (dp[i][j][mask] + fe) % md;
            else dp[i][j][mask] = (dp[i][j][mask] + f0) % md;

            // East
            if (j < w && ((mask & 3) == 0))
                dp[i][j][mask] = (dp[i][j][mask] + fe) % md;
            else if (i < h && ((mask & 1) == 0))
                dp[i][j][mask] = (dp[i][j][mask] + fs) % md;
            else dp[i][j][mask] = (dp[i][j][mask] + f0) % md;

            //printf("%d %d %d\n", f0, fs, fe);
            //printf("dp(%d, %d, %d) = %d\n", i, j, mask, dp[i][j][mask]);
        }
        return dp[1][1][0];
    }
};
