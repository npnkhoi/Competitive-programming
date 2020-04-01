#include <bits/stdc++.h>
using namespace std;

int n, val;
long long s, minS, res;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// scanf("%d", &n);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		// scanf("%d", &val);
		cin >> val;
		s += val;
		res = max(res, s - minS);
		minS = min(minS, s);
	}
	// printf("%lld", res);
	cout << res;
}