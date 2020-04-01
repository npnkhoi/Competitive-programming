#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int tc, n, k, mark[N];
vector<int> v;

int sum(int l, int r) {
	cerr << "get sum " << l << " " << r << " " << v.size() << "\n"; 
	int res = 0;
	for (int i = l; i <= r; ++ i) {
		res += v[i];
	}
	return res;
}

int ans(int n, int k) {
	for (int i = 1; i <= k; ++ i) {
		n += n % 100;
	}
	return n;
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &n, &k);
		// cout << "ans " << ans(n, k) << "\n";
		memset(mark, 0, sizeof mark);
		v.clear();
		long long res = n;
		n %= 100;
		for (int i = 1; i <= k; ++ i) {
			// cerr << "n = " << n << "\n";
			if (mark[n] != 0) {
				int cyc = i - mark[n];
				res += 1LL * (k - i) / cyc * sum(mark[n] - 1, (int) v.size() - 1);
				res += sum(mark[n] - 1, mark[n] - 1 + (k - mark[n]) % cyc); 
				break;
			} else {
				res += n;
				// cerr << res << "\n";
				mark[n] = i;
				v.push_back(n);
				n = 2 * n % 100;
			}
		}
		printf("%lld\n", res);
	}
}