#include <bits/stdc++.h>
using namespace std;

mt19937_64 mt(1337);
uniform_int_distribution<long long> uni(1, 1E15);

const int N = 2500 + 5;

int n, m, q;
long long ft[N][N];
map<pair<pair<int, int>, pair<int, int>>, long long> id;

void update(int u, int v, long long val) {
	for (int i = u; i <= n; i += i & -i) {
		for (int j = v; j <= m; j += j & -j) {
			// cerr << "update " << i << ' ' << j << '\n';
			ft[i][j] += val;
		}
	}
}

long long get(int u, int v) {
	long long ret = 0;
	for (int i = u; i; i -= i & -i) {
		for (int j = v; j; j -= j & -j) {
			ret += ft[i][j];
		}
	}
	return ret;
}

int main() {
	cin >> n >> m >> q;
	while (q --) {
		int t, r1, c1, r2, c2;
		cin >> t >> r1 >> c1 >> r2 >> c2;
		if (t == 3) {
			cout << (get(r1, c1) == get(r2, c2) ? "Yes\n" : "No\n");
			// cerr << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
			// cerr << get(r1, c1) << ' ' << get(r2, c2) << '\n';
		} else {
			long long ran;

			if (t == 1) {
				id[{{r1, c1}, {r2, c2}}] = ran = uni(mt);
			} else {
				ran = - id[{{r1, c1}, {r2, c2}}];
				id.erase({{r1, c1}, {r2, c2}});
			}
			// cerr << "ran = " << ran << '\n';
			update(r1, c1, ran);
			update(r2 + 1, c2 + 1, ran);
			update(r1, c2 + 1, -ran);
			update(r2 + 1, c1, -ran);
		}
	}
}