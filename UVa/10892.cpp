using namespace std;
#include <stdio.h>
#include <cmath>

int n, m;
int main() {
    while(scanf("%d", &n)) {
        if (n == 0) break;
        int m = n;
        long long s = 1;

        for (int i = 2; i <= sqrt(n) + 4; i++)
        if (m % i == 0) {
            int t = 0;
            while (m % i == 0) t++, m /= i;
            s = s * (2 * t + 1);
            //printf("%d %lld\n", m, s);
        }
        if (m != 1) s *= 3LL;
        printf("%d %lld\n", n, s/2 + 1);
    }
}
