using namespace std;
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cmath>

const int N = 1e7 + 10;
long long n;
vector<int> v;
int prime[N];
void sieve() {
    memset(prime, -1, sizeof prime);
    for (int i = 2; i < N; i ++) if (prime[i] == -1) {
        prime[i] = 1;
        v.push_back(i);
        for (long long j = 1LL * i*i; j < N; j += i) prime[j] = 0;
    }
}

int main() {
    //freopen("test.inp" ,"r", stdin);
    //freopen("test.out" ,"w", stdout);
    sieve();
    while(scanf("%lld", &n)) {
        if (n == 0) break;
        n = abs(n);
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int mid = (l+r)/2;
            if (v[mid] > sqrt(n)) r = mid;
            else l = mid + 1;
        }
        long long res = 1;
        int cnt = 0;
        for (int i = l; i >= 0; i--) if (n % v[i] == 0) {
            cnt ++;
            res = max(res, (long long) v[i]);
            while (n % v[i] == 0) n /= v[i];
        }
        if (n != 1) cnt ++, res = max(res, n);

        if (cnt < 2) printf("-1\n");
        else printf("%lld\n", res);
    }
}
