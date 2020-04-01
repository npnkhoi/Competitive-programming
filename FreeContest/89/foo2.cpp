#include <bits/stdc++.h>
using namespace std;

#define task "WC2"

const long long md = 1e9 + 7;

int tc, n;
vector<long long> primes;
int notPrime[(int) 1e7 + 5];
priority_queue<long long, vector<long long>, greater<long long> > heap;

void sieve() {
    for (int i = 2; i <= 1e7; i ++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            //cerr << i << "\n";
            for (long long j = 1LL * i * i; j <= 1e7; j += i) {
                notPrime[j] = 1;
            }
        }
    }
}

int countDiv(int val) {
    int res = 1;
    for (int i = 0; primes[i] <= sqrt(val); ++ i) {
        int cnt = 0;
        while (val % primes[i] == 0) {
            val /= primes[i];
            cnt ++;
        }
        res *= cnt + 1;
    }
    if (val > 1) res *= 2; 
    return res;
}

int main() {
    // freopen(task".inp", "r", stdout);
    sieve();
    int ma = 0, res;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        int tmp = countDiv(i);
        // cerr << tmp << "\n";
        if (tmp > ma) {
            ma = tmp;
            res = i;
        }
    }
    printf("%d", res);
}
