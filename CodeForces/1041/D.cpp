#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, h;
pair<long long, long long> seg[N];
long long res, a[N], s[N];

int main() {
	scanf("%d%d", &n, &h);
	// l[0] = r[0] = - 1e9;
	// l[n + 1] = r[n + 1] = 2e9;

	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &seg[i].first, &seg[i].second);
	}
	sort(seg + 1, seg + n + 1);
	int j = 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i-1] + (seg[i].second - seg[i].first); // sum of ascending area
		while (s[i] - s[j] >= h) ++j;
		res = max(res, (a[i] - a[j-1]) + h);	
		s[i + 1] = s[i] + (seg[i + 1].first - seg[i].second); // sum of gravity area
	}	
	printf("%lld\n", res);
}