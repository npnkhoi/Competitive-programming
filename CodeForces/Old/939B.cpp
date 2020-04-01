#include <cstdio>
#include <utility>
using namespace std;

long long n, c;
int k;
pair<int, long long> ans;
int main() {
    scanf("%lld %d", &n, &k);
    long long tmp = n;
    ans = make_pair(1, 0);
    for (int i = 1; i <= k; i++) {
        scanf("%lld", &c);
        if (n % c < tmp) {
            tmp = n % c;
            ans = make_pair(i, n / c);
        }
    }
    printf("%d %lld", ans.first, ans.second);
}
