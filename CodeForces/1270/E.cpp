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
	for (int i = 1; i < n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			v.push_back({dist(a[i], a[j]), {i, j}});
		}
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); ++ i) {
		if (v[i].first == v[i-1].first) {

		}
	}
}