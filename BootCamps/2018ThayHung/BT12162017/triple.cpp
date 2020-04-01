#include <cstdio>
#include <algorithm>
using namespace std;
#define task "triple"

const int N = 5005;
long long a[N];
int n;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n-2; i++) {
        for (int j = i+1; j <= n-1; j++)
        if (binary_search(a+j+1, a+n+1, 2*a[j] - a[i])) {
            printf("%lld %lld %lld\n", a[i], a[j], 2*a[j] - a[i]);
            exit(0);
        }
    }
    printf("0");
}
