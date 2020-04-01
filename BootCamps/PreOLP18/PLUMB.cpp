#include <cstdio>
#include <algorithm>
using namespace std;

const int D = 1e5 + 5;
int d, p, dp[D];
int main() {
    scanf("%d%d", &d, &p);
    dp[0] = 1e9 + 7;
    for (int i = 1; i <= p; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        for (int j = d; j >= l; j--) dp[j] = max(dp[j], min(dp[j-l], r));
    }
    printf("%d", dp[d]);
}
