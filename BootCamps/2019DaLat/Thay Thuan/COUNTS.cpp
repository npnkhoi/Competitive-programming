// find [l .. r] satisfying s[r] <= s[l-1]

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, t, b[N];
long long a[N], ft[N], res;

long long get(int i) {
	long long res = 0;
	for (; i; i -= i & -i) res += ft[i];
	return res;
}

long long get(int l, int r) {
	return get(r) - get(l - 1);
}

void update(int i, int val) {
	for (; i <= n + 1; i += i & -i) ft[i] += val;
}

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld", &a[i]);
		a[i] = a[i-1] + a[i] - t;
		b[i] = i;
	}
	// for (int i = 0; i <= n; ++ i) cerr << a[i] << " ";
	// cerr << "\n";

	sort(b, b + n + 1, [](int i, int j) {
		if (a[i] != a[j]) return a[i] > a[j];
		else return i < j;
	});

	// for (int i = 0; i <= n; ++ i) cerr << b[i] << " ";
	// cerr << "\n";

	for (int i = 0; i <= n; ++ i) {
		res += get(b[i] + 1);
		update(b[i] + 1, +1);
	}
	printf("%lld", res);
}