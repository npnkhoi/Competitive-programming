#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, a[N], cnt[N];
long long res;

int main() {
	scanf("%d", &n);
	int j = 1;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		cnt[a[i]] ++;
		while (cnt[a[i]] > 2) {
			cnt[a[j]] --;
			j ++;
		}
		res += i - j + 1;
	}
	printf("%lld\n", res);
}
