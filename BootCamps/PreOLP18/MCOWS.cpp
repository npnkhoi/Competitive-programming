#include <cstdio>
using namespace std;

long long n;
int cntDigit(int x) {
    int cnt = 0;
    while (x) {
        cnt ++;
        x /= 10;
    }
    return cnt;
}
int main() {
    scanf("%lld", &n);
    int x = cntDigit(n);
    long long tmp = 9, res = 0;
    for (int i = 1; i < x; i++, tmp *= 10) res += tmp * i;
    res += x * (n - tmp/9 + 1);
    printf("%lld", res);
}
