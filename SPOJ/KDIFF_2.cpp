#include <bits/stdc++.h>
using namespace std;

#define task "KDIFF"

const int N = 3e5 + 5;
const int oo = 1e9 + 7;

int a[N], f[N], g[N], n, k, res;
deque<int> mi, ma;

int main() {
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &k);
	f[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		//cerr << i << "\n";
		scanf("%d", &a[i]);

		while (!mi.empty() && a[mi.back()] > a[i]) {
			// cerr << "pop min " << mi.back() << "\n";
			mi.pop_back();
		}
		mi.push_back(i);
		while (!ma.empty() && a[ma.back()] < a[i]) {
			// cerr << "pop max " << ma.back() << "\n";
			ma.pop_back();
		}
		ma.push_back(i);

		for (int j = f[i-1]; j <= i; ++ j) {
			if (a[ma.front()] - a[mi.front()] <= k) {
				//cerr << j << " " << "diff = " << a[ma.front()] - a[mi.front()] << "\n";
				f[i] = j;
				break;
			}
			if (mi.front() == j) mi.pop_front();
			if (ma.front() == j) ma.pop_front();
		}
		
		//cerr << i << " " << f[i] << "\n";
		g[i] = max(g[i-1], i - f[i] + 1);
		res = max(res, i - f[i] + 1 + g[f[i] - 1]);
		//cerr << res << "\n";
	}	

	printf("%d\n", res);
}