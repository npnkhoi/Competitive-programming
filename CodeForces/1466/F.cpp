#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, md = 1e9 + 7;

typedef pair<pair<int, int>, int> Edge;

int n, m, dsu[N], mark[N];
vector<Edge> edges;
vector<int> ans;
vector<int> ones;

int root(int u) {
	if (dsu[u] < 0) return u;
	dsu[u] = root(dsu[u]);
	return dsu[u];
}

bool merge(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return false;
	if (dsu[u] > dsu[v]) {
		swap(u, v);
	}
	dsu[u] --;
	dsu[v] = u;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	memset(dsu, -1, sizeof dsu);
	long long t = 1;
	for (int i = 1; i <= n; ++ i) {
		int k, x, y;
		cin >> k;
		if (k == 1) {
			cin >> x;
			y = 0;
		} else {
			cin >> x >> y;
		}
		if (merge(x, y)) {
			t = t * 2 % md;
			ans.push_back(i);
		}
	}
	cout << t << ' ' << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
}