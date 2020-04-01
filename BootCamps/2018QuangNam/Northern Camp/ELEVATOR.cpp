using namespace std;
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
const int N = 110;
const long long oo = 1e18 + 7;

typedef pair<long long, long long> pll;
long long n, c, p, t;
long long s[N];
map<pll, long long> memo;
//long long memo[N][N];

long long f(long long i, long long j) {
    if (memo.find(pll(i, j)) != memo.end()) return memo[pll(i, j)];
    if (i < 0 || j > s[n]) return -oo;
    //if (memo[i][j] != -1) return memo[i][j];

    int x = upper_bound(s + 1, s + n + 1, j) - s;
    //printf("%d %lld\n", x, s[x]);
    //printf("%lld %lld\n", i - 2*p*x, j + c);
    //printf("%lld %lld\n", i - 2*p*(x-1), s[x-1]);
    long long ans = 0;
    for (; x <= n && s[x] - j <= c && i >= 2*p*x; x++)
        ans = max(ans, s[x] - j + f(i - 2*p*x, s[x]));
    if (s[x-1] - j < c) ans = max(ans, c + f(i - 2*p*x, j + c));
    memo[pll(i, j)] = ans;
    return ans;
}
int main () {
    freopen("elevator.inp", "r", stdin);
    freopen("elevator.out", "w", stdout);

    scanf("%lld %lld %lld %lld", &n, &c, &p, &t);
    //printf("%lld %lld %lld %lld\n", n, c, p, t);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &s[i]),
        s[i] += s[i-1];
    //memset(memo, -1, sizeof memo);
    printf("%lld", f(t, 0));
}
