using namespace std;
#include <stdio.h>
#include <string.h>
#include <cmath>
const int N = 1e7 + 10;
int prime[N];
int n, m;

int deg(int x, int a) {
    // return degree of x in fratorization form of a!
    long long t = x;
    int s = 0;
    while (t <= a) s += a/t, t = t*x;x
    return s;
}

void sieve() {
    memset(prime, -1, sizeof prime);
    for (int i = 2; i < N; i++)
    if (prime[i] == -1) {
        prime[i] = 1;
        for (long long j = i*i; j < N; j++) prime[j] = 0;
    }
}
int main() {
    //sieve();
    while (scanf("%d %d", &n, &m) != EOF) {
        int k = m;
        for (int i = 2; i <= sqrt(k) + 1; i++) if (m%i == 0) {
            int t = 0;
            while (m%i == 0) m/=i, t++;
            if (t > deg(i, n)) {
                printf("%d does not divide %d!\n", k, n);
                m = -1;
                break;
            }
        }
        if (m == -1) continue;
        if (m != 1 && m > n) printf("%d does not divide %d!\n", k, n);
        else printf("%d divides %d!\n", k, n);
    }
}
