#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int M = 1005;
const int N = 1e6 + 5;
const int A = 2e6 + 5;
const int oo = N;
const int sh = 1e6;
#define task "LCS"

int m, n, maxLength;
int a[M], b[N], dp[M][M];
vector<int> pos[A];

int nextPos(int idx, int val) {
    int res = upper_bound(pos[val].begin(), pos[val].end(), idx) - pos[val].begin();
    if (res == pos[val].size()) return oo;
    else return pos[val][res];
}
void trace(int i, int j) {
    if (i == 0) return;
    if (dp[i][j] == dp[i-1][j]) trace(i-1, j);
    else {
        trace(i-1, j-1);
        printf("%d ", b[dp[i][j]] - sh);
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    int maxLength = min(m , n);
    //cerr << maxLength << "\n";
    for (int i = 1; i <=  m; ++i) {
        scanf("%d", &a[i]);
        a[i] += sh;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        b[i] += sh;
        pos[b[i]].push_back(i);
    }
    for (int j = 1; j <= maxLength; ++j) dp[0][j] = oo;

    int res = 0, x = 0, y = 0;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= maxLength; ++j) {
        dp[i][j] = min(nextPos(dp[i-1][j-1], a[i]), dp[i-1][j]);
        if (dp[i][j] != oo && j > y) x = i, y = j;
    }
    printf("%d\n", y);
    trace(x, y);
}
