#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

int isPrime[N];
vector<int> prime;

void sieve() { // remember to call this beneath "int main()"
    memset(isPrime, -1, sizeof isPrime);
    for (int i = 2; i < N; i++) if (isPrime[i] == -1){
        prime.push_back(i);
        //printf("%d\n", i);
        for (long long j = 1LL*i*i; j < N; j+=i) isPrime[j] = 0;
    }
}

int main() {
	sieve();
	long long tmp = 1;
	for (int i = 0; i < 20; ++ i) {
		if (tmp * prime[i] <= 3e5) {
			tmp *= prime[i];
			cerr << i << " " << prime[i] << " " << tmp << "\n";
		} else break;
	}
}