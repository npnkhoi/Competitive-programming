#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<long long, long long> Point;

const int N = 1005;

int n, mark[N];
Point a[N];
pair<long long, int> v[N];
vector<int> adj[N], ans;

long long dist(Point A, Point B) {
	return (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y);
}

void dfs(int u) {
	mark[u] = 1;
	ans.push_back(u);
	for (int v : adj[u]) {
		if (mark[v]) continue;
		dfs(v); 
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i].X >> a[i].Y;
	}
	for (int i = 1; i <= n; ++ i) {
		int idx = 0;
		for (int j = 1; j <= n; ++ j) {
			if (j == i) continue;
			v[idx] = {dist(a[i], a[j]), j};
			idx ++;
		}
		sort(v, v + idx);
		for (int j = 1; j < idx; ++ j) {
			if (v[j - 1].first == v[j].first) {
				adj[v[j - 1].second].push_back(v[j].second);
				adj[v[j].second].push_back(v[j - 1].second);
			}
		}
	}
	dfs(1);
	cout << ans.size() << '\n';
	for (int x : ans) cout << x << ' ';
}