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

int main() {
    // freopen(task".inp", "r", stdout);
    sieve();
    scanf("%d", &tc);
    while (tc -- ) {
        while (!heap.empty()) heap.pop();
        scanf("%d", &n);
        long long res = 1;
        int idx = 0;
        for (int i = 1; i <= n; i ++) {
            if (!heap.empty() && heap.top() < primes[idx]) {
                long long tmp = heap.top();
                heap.pop();
                heap.push(tmp * tmp);
                res = res * tmp % md;
            } else {
                res = res * primes[idx] % md;
                heap.push(primes[idx] * primes[idx] % md);
                idx ++;
            }
            cerr << i << " " << res << "\n";
        }
        printf("%lld\n", res);
    }
}
