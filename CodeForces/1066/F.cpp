#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct Point {
	int x, y;
};

int dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int n, m;
Point a[N];
vector<vector<int> > p;
long long f[N][2], s[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a + n + 1, [](Point a, Point b) {
		if (max(a.x, a.y) != max(b.x, b.y)) {
			return max(a.x, a.y) < max(b.x, b.y);
		} else if (a.x != b.x) return a.x < b.x;
		else return (a.y > b.y);
	});
	m = 0;
	for (int i = 0; i <= n; ++ i) {
		if (i == 0 || max(a[i].x, a[i].y) != max(a[i - 1].x, a[i - 1].y)) {
			p.resize(p.size() + 1);
			++ m;
		}
		if (!p[m - 1].empty()) {
			s[m - 1] += abs(a[i].x - a[p[m - 1].back()].x) + abs(a[i].y - a[p[m - 1].back()].y);
		}
		p[m - 1].push_back(i);
	}
	// for (int i = 0; i < m; ++ i) {
	// 	for (int v : p[i]) {
	// 		cerr << a[v].x << " " << a[v].y << ", ";
	// 	}
	// 	cerr << "\n";
	// }
	f[0][0] = f[0][1] = 0;
	for (int i = 1; i < m; ++ i) {
		f[i][0] = s[i] + min(f[i-1][0] + dist(a[p[i - 1][0]], a[p[i].back()]), 
			f[i - 1][1] + dist(a[p[i - 1].back()], a[p[i].back()]));
		f[i][1] = s[i] + min(f[i-1][0] + dist(a[p[i - 1][0]], a[p[i][0]]), 
			f[i - 1][1] + dist(a[p[i - 1].back()], a[p[i][0]]));
		// cerr << "f[] = " << f[i][0] << " " << f[i][1] << "\n";
	}
	printf("%lld", min(f[m - 1][0], f[m - 1][1]));
}