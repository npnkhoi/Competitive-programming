#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, MAX_VAL = 5e5;

int n, a[N], ft[3 * N], mark[N];
vector<int> pos[N];
long long res;

void update(int i, int val) {
	while (i <= 3 * n + 1) {
		ft[i] += val;
		i += i & -i;
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += ft[i];
		i -= i & -i;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	// if (n > 1000) {
	// 	printf("%lld\n", (long long) n * (n + 1) / 2);
	// 	exit(0);
	// }
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	res = (long long) n * (n + 1) / 2;
	// cerr << res << '\n';
	for (int val = 1; val <= MAX_VAL; ++ val) {
		if (pos[val].empty()) continue;

		memset(ft, 0, sizeof ft);
		memset(mark, 0, sizeof mark);
		for (int x : pos[val]) mark[x] = 1;

		int s = n + 1;
		update(s, +1);
		for (int i = 1; i <= n; ++ i) {
			if (mark[i]) s += 1;
			else s -= 1;
			res -= get(s - 1);
			update(s, +1);
			// cerr << "s = " << s - n - 1 << ", ";
			// cerr << val << ' ' << res << '\n';
		}
 	}
	printf("%lld\n", res);
}