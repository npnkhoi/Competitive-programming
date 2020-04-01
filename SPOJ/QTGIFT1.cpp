#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long memo[N], dp[N];
deque<long long> de;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    de.push_back(0);
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &memo[i]);
        s += memo[i];
        memo[i] += dp[i-1];

        if (de.front() <= i-k) de.pop_front();
        while (!de.empty() && memo[de.back()] >= memo[i])
            de.pop_back();
        de.push_back(i);

        dp[i] = memo[de.front()];
    }
    printf("%lld\n", s-dp[n]);
}
