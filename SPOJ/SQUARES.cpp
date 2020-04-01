#include <cstdio>
#include <iostream>
using namespace std;

const int maxNum = 1e6;
bool sieve[maxNum + 2];
void initPrime() {
    sieve[1] = sieve[0] = 1;
    for (int i = 2; i <= maxNum; i++) if (sieve[i] == 0) {
        for (long long j = 1LL * i * i; j <= maxNum; j += i)
        sieve[j] = 1;
    }
}
int totient(int n) {
    //printf("totient %d\n", n);
    int res = n;
    for (int i = 1; i*i <= n; i++) if (n % i == 0) {
        if (!sieve[i]) res = res / i * (i - 1);
        if (i*i != n) {
            int j = n / i;
            if (!sieve[j]) res = res / j * (j - 1);
        }
    }
    //cerr << res << "\n";
    return res;
}
int calc(int num) {
    //cerr << num << "\n";
    num ++;
    if (num == 2) return 1;
    else return totient(num) / 2;
}
int main() {
    initPrime();
    long long res = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i*i <= n; i++) if (n % i == 0) {
        res += calc(i);
        if (i * i != n) res += calc(n / i);
    }
    printf("%lld", res);
}
