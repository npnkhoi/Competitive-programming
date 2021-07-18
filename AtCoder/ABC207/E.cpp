#include <bits/stdc++.h>
using namespace std;

const int N = 3005, MOD = 1e9+7;

int last[N];
long long a[N], dp[N][N], sum[N];

long long add(long long sum, long long x) {
    sum += x;
    if (sum >= MOD) {
        sum -= MOD; 
    
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    
    dp[0][0] = 1;
    for (int block = 1; block <= n; ++ block) {
        memset(last, -1, sizeof last);
        last[0] = 0;
        for (int pos = 1; pos <= n; ++ pos) {
            long long rem = sum[pos] % block;
            int prePos = last[rem];
            if (prePos != -1) {
                dp[block][pos] = add(dp[block][pos], dp[block-1][prePos]);
                dp[block][pos] = add(dp[block][pos], dp[block][prePos]);
            }
            last[rem] = pos; 
        }
    }
    
    long long res = 0;
    for (int block = 1; block <= n; ++ block) {
        res = add(res, dp[block][n]);
    }
    cout << res;
}
