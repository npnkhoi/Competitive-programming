using namespace std;
#include <stdio.h>
#include <vector>
#include <string.h>
#include <cmath>
const int N = 1e6 + 10;
int n, deg[N], cnt[N],
int prime[N];
vector<int> v;
void sieve() {
    memset(prime, -1, sizeof prime);
    for (int i = 2; i < N; i++) if (prime[i] == -1){
        //v.push_back(i);
        //printf("%d\n", i);
        for (long long j = 1LL*i*i; j < N; j+=i) prime[j] = 0;
    }
}

int Log(int a, int n) {
    if (a > n) return 0;
    else return 1 + Log(a, n/a);
}

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    sieve();

    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        int res = 1;
        int t = Log(2, n) - Log(5, n);
        if (t > 0) while (t--) res = (res * 2) % 10;
        //printf("%d\n", res);

        for (int i = 0; i < v.size() && v[i] <= n; i++)
        if (v[i] != 2 && v[i] != 5) {
            int t = Log(v[i], n);
            //printf("%d %d\n", v[i], t);
            while (t--) res = (res * (v[i] % 10)) % 10;
        }
        printf("%d\n", res);
    }
}
