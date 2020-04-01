#include <bits/stdc++.h>
using namespace std;
const int A = 8e6;
int mark[A + 5];
vector<long long> prime;
int n, k, a;

void sieve() {
    for (int i = 2; i <= A; i++) if (!mark[i]) {
        prime.push_back(i);
        for (long long j = 1LL * i * i; j <= A; j += i)
        mark[j] = 1;
    }
}
int dec(int val, int d) {
    return (val + (n - d % n)) % n;
}
int inc(int val, int d) {
    return (val + d) % n;
}
/*int f1(int x, int d) {
    if (x == 0) return (d % n);
    else if (d >= x) return dec(x, 1 + (d-x) / (n-1));
    else return x;
}
int f2(int x, int d) {
    if (x == d % (n-1)) return 0;
    else {
        x = inc(x, d / (n-1));
        if (x <= d / (n-1)) x = inc(x, 1);

    }
}*/
int fw(int x, int p) {
    if (x == 0) return p % n;
    else {
        if (x <= p % (n-1)) x = dec(x, 1);
        x = dec(x, p / (n-1));
        return x;
    }
}
int bw(int x, int p) {
    if (x == p%n) return 0;
    else {
        x = inc(x, p / (n-1));
        if (x <= p % (n-1))
            x = inc(x, 1);
        return x;
    }
}

int main() {
    freopen("neighbor.inp", "r", stdin);
    freopen("neighbor.out", "w", stdout);
    sieve();
    scanf("%d%d%d", &n, &k, &a); a --;
    for (int i = 0; i < k; i++) {
        a = fw(a, prime[i]);
        //cerr << prime[i] << " " << a << "\n";
    }
    int x = dec(a, 1), y = inc(a, 1);
    for (int i = k-1; i >= 0; i--) {
        x = bw(x, prime[i]);
        y = bw(y, prime[i]);
    }
    printf("%d %d", y + 1, x + 1);
}
