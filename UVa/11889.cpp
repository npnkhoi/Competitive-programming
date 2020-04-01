using namespace std;
#include <stdio.h>
#include <string.h>
#include <cmath>

const int N = 1e7 + 10;

int main() {
    int tc;
    scanf("%d", &tc);

    while(tc--)  {
        int a, c;
        scanf("%d %d", &a, &c);
        if (c%a) {
            printf("NO SOLUTION\n");
            continue;
        }

        int n = c;
        int b = 1;

        for (int i = 2; i <= sqrt(n) + 4; i++) if (c % i == 0) {
            int t = 1;

            while (a%i == 0) t *= i, a /= i, c /= i;

            if (c%i == 0) {
                while (c%i == 0) t *= i, c /= i;
                b *= t;
            }
        }

        if (a == 1 && c > 1) b *= c;
        printf("%d\n", b);
    }
}
