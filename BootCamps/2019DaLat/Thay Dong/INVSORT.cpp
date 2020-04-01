#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], ft[N], f[N];
vector<pair<int, int> > ans, v;

int get(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += ft[i];
	return res;
}

void udpate(int i, int val) {
	for (; i <= n; i += i & -i) ft[i] += val;
}

int main() {
	freopen("INVSORT.inp", "r", stdin);
	freopen("INVSORT.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		v.push_back(make_pair(-a[i], i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++ i) {
		f[v[i].second] = get(v[i].second);
		udpate(v[i].second, +1);
	}
	for (int i = 1; i <= n; ++ i) {
		if (f[i] > 0) {
			ans.push_back(make_pair(i - f[i], i - 1));
			ans.push_back(make_pair(i - f[i], i));
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++ i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}