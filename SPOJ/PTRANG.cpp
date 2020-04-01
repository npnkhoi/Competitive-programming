#include <bits/stdc++.h>
using namespace std;
const int N = 6e3 + 5;
int a[N], dp[N];

int length(int l, int r) {
    return a[r] - a[l-1] + (r-l);
}
int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        //printf("dp[%d]\n", i);
        dp[i] = l;
        for (int j = i-1; j >= 0 && length(j+1, i) <= l; j--)
        dp[i] = min(dp[i], max(dp[j], l - length(j+1, i)));
    }
    cout << dp[n];
}
