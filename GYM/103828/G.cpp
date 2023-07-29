#include <bits/stdc++.h>
using namespace std;

long long f[11];

void solve(long long n) {

    long long k = (long long) ceil(sqrt(n));
    long long m = k * k;
    long long d = m - n;

    long long sumF = 0;

    for (int d = 9; d >= 4; d --) {
        int coef = d * d - 1;
        long long cand = m / coef;
        cand = min(cand, n - sumF);



        m -= coef * cand;
        if (m < 14 && cand )
        sumF += cand;
        f[d] = cand;
    }

}

int main() {
    int tc;
    cin >> tc;
    cin >> n;
    solve(n);
}
