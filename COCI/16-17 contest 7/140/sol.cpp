#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> tri;

const int N = 405;

int n;
int x[N], y[N];
map<tri, tri> pre;
vector<tuple<int, int, int>> ans;

void input() {
	scanf("%d", &n);
	bool ok = 1;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d %d", &x[i], &y[i]);
		if (x[i] <= 0 || y[i] <= 0) ok = 0;
	}
	if (ok) {
		printf("0\n");
		exit(0);
	}
}

void checkTri() {
	bool hasTri = 0;
	for (int i = 1; i <= n - 2; ++ i) {
		for (int j = i + 1; j <= n - 1; ++ j) {
			for (int k = j + 1; k <= n; ++ k) {
				if ((x[i] - x[j]) * (y[i] - y[k]) != (x[i] - x[k]) * (y[i] - y[j])) {
					hasTri = 1;
					break;
				}
			}
		}
	}
	if (hasTri == 0) {
		printf("-1\n");
		exit(0);
	} 
}

void trace(tri t) {
	// cerr << t[0].first << ' ' << t[0].second << ' ' << t[1].first << ' ' << t[1].second << ' ' << t[2].first << ' ' << t[2].second << '\n';
	if (pre[t] != t) trace(pre[t]);
	else return;

	int x = 0;
	while (t[x] == pre[t][x]) x ++;
	// cerr << "x = " << x << '\n';
	int y = (x + 1) % 3;
	int z = (y + 1) % 3;
	ans.push_back({y + 1, z + 1, x + 1});
}

void move123() {
	tri v = {{x[1], y[1]}, {x[2], y[2]}, {x[3], y[3]}};
	// sort(v.begin(), v.end());

	queue<tri> q;
	q.push(v);
	
	pre[v] = v;

	while (1) {
		tri f = q.front(); q.pop();
		// cerr << f[0].first << ' ' << f[0].second << ' ' << f[1].first << ' ' << f[1].second << ' ' << f[2].first << ' ' << f[2].second << '\n';
		if (f[0].first >= 5 && f[0].second >= 5 &&
				f[1].first >= 5 && f[1].second >= 5 &&
				f[2].first >= 5 && f[2].second >= 5) {
			trace(f);
			return;
		} else {
			for (int x = 0; x < 3; ++ x) {
				int y = (x + 1) % 3;
				int z = (y + 1) % 3;
				tri t = f;
				t[x].first = t[y].first + t[z].first - t[x].first;
				t[x].second = t[y].second + t[z].second - t[x].second;

				if (t[0].first >= -10 && t[0].second >= -10 &&
						t[1].first >= -10 && t[1].second >= -10 &&
						t[2].first >= -10 && t[2].second >= -10 &&
						pre.find(t) == pre.end()) {
					q.push(t);
					pre[t] = f;
				}
			}
		}
	}
}

int main() {
	input();
	checkTri();
	move123();	
	for (int i = 4; i <= n; ++ i) {
		if (x[i] <= 0 || y[i] <= 0) {
			ans.push_back({1, 2, i});
		} 
	}

	printf("%d\n", ans.size());
	for (auto x : ans) printf("%d %d %d\n", get<0>(x), get<1>(x), get<2>(x));
}