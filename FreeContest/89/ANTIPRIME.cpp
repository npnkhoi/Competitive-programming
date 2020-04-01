#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> primes;
int notPrime[(int) 1e7 + 5];
priority_queue<long long, vector<long long>, greater<long long> > heap;

void sieve() {
    for (int i = 2; i <= 1e7; i ++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            // cerr << i << "\n";
            for (long long j = 1LL * i * i; j <= 1e7; j += i) {
                notPrime[j] = 1;
            }
        }
    }
    cerr << "done sieve\n";
}

int main() {
    // freopen(task".inp", "r", stdin);
    // freopen(task".out", "w", stdout);
    sieve();
    cerr << primes.size() << "\n";
    cerr << primes[0] << "\n";
    long long res = 1, nxt;
    int idx = 0;
    scanf("%lld", &n);
    while (res < n) {
        if (!heap.empty() && heap.top() < primes[idx]) {
            // cerr << "if 1\n";
            long long tmp = heap.top();
            heap.pop();
            heap.push(tmp * tmp);
            nxt = res * tmp;
            if (nxt < res || nxt > n) break;
            else res = nxt;
        } else {
            // cerr << "if 2\n";
            // cerr << idx << "\n";
            // cerr << primes.size() << "\n";
            // cerr << primes[0] << "\n";
            nxt = res * primes[idx];
            // cerr << "ok nhan\n";
            if (nxt < res || nxt > n) break;
            else res = nxt;
            heap.push(primes[idx] * primes[idx]);
            idx ++;
        }
        // cerr << res << "\n";
    }
    printf("%lld\n", res);
}
