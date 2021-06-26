#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], deg[N], v[N];

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	int tc; cin >> tc;
	while (tc --) {
		int n; cin >> n;
		long long sum = 0;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i];
			sum += a[i];
		}
		memset(deg, 0, sizeof deg);
		for (int i = 1; i <= n - 1; ++ i) {
			int u, v;
			cin >> u >> v;
			deg[u] ++;
			deg[v] ++;
		}
		int id = 0;
		for (int u = 1; u <= n; ++ u) {
			for (int x = 0; x < deg[u] - 1; ++ x) {
				v[id ++] = a[u];
			}
		}
		// cerr << "id = " << id << '\n';
		// for (int i = 0; i < id; ++ i) {
		// 	cerr << v[i] << ' ';
		// }
		// cerr << '\n';
		sort(v, v + id);
		for (int i = id - 1; i >= 0; --i) {
			cout << sum << ' ';
			sum += v[i];
		}
		cout << sum << "\n";
	}
}