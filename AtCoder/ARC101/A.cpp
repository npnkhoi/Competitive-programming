#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
int n, k, val, res;
vector<int> a, b;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &val);
		if (val < 0) a.push_back(val);
		else b.push_back(val);
	}
	reverse(a.begin(), a.end());
	res = oo;
	for (int i = 0; i <= k; i ++) {
		if (i <= a.size() && k - i <= b.size()) {
			int tmp1 = 0, tmp2 = 0;
			if (i > 0) tmp1 = abs(a[i - 1]);
			if (k - i > 0) tmp2 = abs(b[k - i - 1]);
			res = min(res, tmp1 + tmp2 + min(tmp1, tmp2));
		}
	}
	printf("%d", res);
}