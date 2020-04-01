#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, a[N];
long long s[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i]; 
	}
	if (s[n] % 3 != 0) {
		printf("0\n");
		return 0;
	}
	long long tmp = s[n] / 3, res = 0;
	int cnt = 0;
	for (int i = 1; i < n; ++ i) {
		if (s[i] == 2 * tmp) {
			res += cnt;
		}
		// cerr << cnt << " " << res << "\n";
		cnt += (s[i] == tmp);
	}
	printf("%lld", res);
}