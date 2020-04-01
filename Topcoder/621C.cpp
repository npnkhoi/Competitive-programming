#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5 + 5;

int n, p, x[N], y[N];
double tmp, pro, res;
long long sum1, sum2;

int main() {
    scanf("%d%d", &n, &p);

    pro = 1;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        x[i] = r / p - (l-1) / p;
        y[i] = r - l + 1;
        tmp += (double) x[i] / y[i];
        pro /= y[i];
        sum1 += x[i];
        sum2 += x[i] * x[i];
    }
    //cerr << tmp << " " << sum1 << " " << sum2 << " " << pro << "\n";
    res = (n-1) * tmp - (sum1 * sum1 - sum2) * pro;
    res *= 2000;

    printf("%.10f", res);

}
