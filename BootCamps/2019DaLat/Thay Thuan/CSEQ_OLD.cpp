#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, p;
int a[N], ft[N];
long long s[N], res;
vector<long long> vals;

int getID(long long x) {
	return upper_bound(vals.begin(), vals.end(), x) - vals.begin();
}

void update(int i, int val) {
	// cerr << "update " << i << " " << val << "\n";
	for (; i <= p; i += i & -i) ft[i] += val;
}

int get(int i) {
	// cerr << "get " << i << "\n";
	long long res = 0;
	for (; i; i -= i & -i) res += ft[i];
	return res;
}

int get(int l, int r) {
	if (l == 0) return get(r);
	return get(r) - get(l - 1);
}

int main() {
	scanf("%d%d", &n, &m);
	vals.push_back(0);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i]; // long long
		vals.push_back(s[i]);
	}
	// compress
	sort(vals.begin(), vals.end());
	p = unique(vals.begin(), vals.end()) - vals.begin();
	vals.resize(p);

	for (int i = 0; i < vals.size(); ++i) cerr << i << " " << vals[i] << "\n";

	cerr << "ok\n";

	for (int i = 0; i <= n; ++ i) {
		res += get(getID(s[i] - m), p);
		update(getID(s[i]), 1);
		cerr << i << " " << res << "\n";
	}
	printf("%lld", res);
}