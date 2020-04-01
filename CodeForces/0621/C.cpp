#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5 + 5;

int n, p;
long long x[N], y[N];
double tmp, pro, res;
double s1, s2;
long long sum1, sum2;

int main() {
    scanf("%d%d", &n, &p);

    pro = 1;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        x[i] = r / p - (l-1) / p;
        y[i] = r - l + 1;
    }
    for (int i = 1; i <= n; ++i) {
        int j;
        if (i == n) j = 1; else j = i + 1;
        res += (double) (x[i] * y[j] + y[i] * x[j] - x[i] * x[j]) / (y[i] * y[j]);
    }
    res *= 2000;

    printf("%.10f", res);

}
