#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
long long res;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		a[i] -= i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		res += abs(a[i] - a[(n + 1) / 2]);
	}
	printf("%lld", res);
}