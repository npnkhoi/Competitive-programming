#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long m, s[N];
int n, a[N];

long long count(int x) {
	long long ret = 0;
	for (int u = 0, v = n-1; u < n; ++ u) {
		if (a[u] + a[v] < x) continue;
		while (v >= 0 && a[u] + a[v] >= x) v--;
		v ++;
		ret += (n - v);
		// printf("at u = %d: v = %d, ret = %lld\n", u, v, ret);
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	// cerr << count(67) << '\n';
	int l = a[0] + a[0], r = a[n - 1] + a[n - 1], bs = l;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (count(mid) >= m) {
			bs = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	// cerr << bs << '\n';

	// Suffix sum
	s[n-1] = a[n-1];
	for (int i = n-2; i >= 0; -- i) {
		s[i] = s[i + 1] + a[i];
	}

	// Cal res
	long long res = (m - count(bs + 1)) * bs;
	int bound = bs + 1;
	for (int u = 0, v = n-1; u < n; ++ u) {
		if (a[u] + a[v] < bound) continue;
		while (v >= 0 && a[u] + a[v] >= bound) v--;
		v ++;
		res += 1LL * (n - v) * a[u] + s[v];
		// printf("at u = %d: v = %d, ret = %lld\n", u, v, ret);
	}
	cout << res;
}