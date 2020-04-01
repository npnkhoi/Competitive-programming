#include <bits/stdc++.h>
using namespace std;
#define task "CHATCAY"
typedef long long ll;
const int N = 2e4 + 5;
const long long oo = 1e17 + 5;
int n;
long long w[N], d[N], s[N], dp[4][N];

long long cost(int x, int y) {
    return (w[y] - w[x-1]) * d[y] - (s[y] - s[x-1]);
}
ll Rand(ll l, ll r) {
    return l + (
    rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    rand() * (RAND_MAX + 1)) % (r-l+1);
}
void makeTest() {
    ofstream inp(task".inp");

    srand(time(NULL));
    int n = 20000;
    inp << n << "\n";
    for (int i = 1; i <= n; i++) inp << Rand(1, 1e4) << " " << Rand(1, 1e4) << "\n";
    inp.close();
}

int main() {
    makeTest();

    double Time = clock();

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d%d", &w[i], &tmp);
        d[i+1] = d[i] + tmp;
        s[i] = s[i-1] + w[i] * d[i];
        w[i] += w[i-1];
    }
    w[n+1] = w[n];
    s[n+1] = s[n];
    for (int i = 0; i <= 2; i++)
    for (int j = 1; j <= n+1; j++)
    if (i == 0) dp[i][j] = cost(1, j);
    else {
        dp[i][j] = oo;
        for (int k = 1; k < j; k++)
            dp[i][j] = min(dp[i][j], dp[i-1][k] + cost(k+1, j));
    }
    printf("%lld", dp[2][n+1]);

    Time = (clock() - Time) / CLOCKS_PER_SEC;
    cerr << Time;

}
