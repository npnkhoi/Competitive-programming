using namespace std;
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cmath>

const int N = sqrt(1e9) + 10;
int isPrime[N];
vector<int> prime;

void sieve() {
    memset(isPrime, -1, sizeof isPrime);
    for (int i = 2; i < N; i++) if (isPrime[i] == -1){
        prime.push_back(i);
        //printf("%d\n", i);
        for (long long j = 1LL*i*i; j < N; j+=i) isPrime[j] = 0;
    }
}

long long numDiv(int n) {
    long long s = 1;
    for (int i = 0; i < prime.size(); i++) if (n % prime[i] == 0) {
        int t = 1;
        while (n % prime[i] == 0) t++, n /= prime[i];
        s *= t;
    }
    if (n > 1) s *= 2;
    //printf("%lld\n", s);
    return s;
}

int main() {
    sieve();
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int l, r;
        scanf("%d %d", &l ,&r);
        long long _max = 0, t;
        int ans;
        for (int i = l; i <= r; i++) if ((t = numDiv(i)) && t > _max)
            _max = t, ans = i;
        printf("Between %d and %d, %d has a maximum of %lld divisors.\n", l, r, ans, _max);
    }
}
