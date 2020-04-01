#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class AB {
    public:
        static const int N = 52;
        static const int K = N * (N+1) / 2;
        bool dp[N][N][K];
        string createString(int n, int k) {
            //cerr << "in\n";
            for (int j = 0; j <= n; j++)
            for (int x = 0; x <= k; x ++)
                dp[0][j][x] = 0;
            dp[0][0][0] = 1;


            for (int i = 1; i <= n; i++)
            for (int j = 0; j <= n; j++)
            for (int x = 0; x <= k; x ++) {
                dp[i][j][x] = 0;
                if (x - j >= 0) dp[i][j][x] |= dp[i-1][j][x - j];
                if (j - 1 >= 0) dp[i][j][x] |= dp[i-1][j-1][x];
                //printf("%d %d %d -> %d\n", i, j, x, int(dp[i][j][x]));
            }
            //cerr << "ok\n";
            for (int j = 0; j <= n; j ++) if (dp[n][j][k]) {
                string ans = "";
                trace(n, j, k, ans);
                return ans;
            }
            return "";
        }
        void trace(int i, int j, int x, string &ans) {
            //printf("Trace %d %d %d\n", i, j, x);
            if (i == 0) return;
            if (x - j >= 0 && dp[i-1][j][x - j]) {
                trace(i-1, j, x-j, ans);
                ans += 'B';
            }
            else {
                trace(i-1, j-1, x, ans);
                ans += 'A';
            }
        }
};
int main() {
    AB tmp;
    cout << (tmp.createString(10, 12));
}
