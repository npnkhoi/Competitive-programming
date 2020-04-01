using namespace std;
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>

const int maxPre = 1e7 + 5;

int pre[maxPre];
int factor[maxPre];
long long N, K, m, n, k;

void sieve() {
    memset(pre, -1, sizeof pre);
    pre[1] = 1;
    for (int i = 2; i < maxPre; i+=2) pre[i] = 2;
    for (int i = 3; i < maxPre; i += 2)
        if (pre[i] == -1)
        for (int j = i; j <= maxPre; j+=i) if (pre[j] == -1) pre[j] = i;
}
long long nCk_m(long long n, long long k, long long m) {
    // make sure that factor[i] = 0 for all i
    k = max(k, n-k);
    for (int i = k + 1; i <= n; i++)
    for (int x = i; x > 1;) factor[pre[x]] ++, x /= pre[x];

    for (int i = 2; i <= n - k; i++)
    for (int x = i; x > 1;) factor[pre[x]] --, x /= pre[x];

    long long res = 1;
    for (int i = 1; i <= n; i++)
    while (factor[i] > 0) res = (res * i) % m, factor[i] --;
    return res%m;
}
long long nCk_p(long long n, long long k, long long p) {
    k = max(k, n - k);
    long long res = 1;
    for (long long i = k + 1; i <= n; i++) res = (res * i) % p;

    for (long long i = 2; i <= n - k; i++) res = (res * (long long) pow(i, p-2)) % p;

    return res%p;
}
int main() {
    freopen("TPCNINJA.inp", "r", stdin);
    freopen("TPCNINJA.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    sieve();
    while (tc--) {
        scanf("%lld %lld %lld", &N, &K, &m);
        k = (N + K - 1) / K;
        n = K - (N%K);
        if (n == K) n = 0;
        printf("%lld ", k);
        k--; n += k;
        //printf("%lld %lld\n", n, k);
        if (n <= 1e7) printf("%lld\n", nCk_m(n, k, m));
        else printf("%lld\n", nCk_p(n, k, m));
    }
}

