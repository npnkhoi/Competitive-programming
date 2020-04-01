#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> Edge;

const int N = 1e5 + 5;

int n, m, lab[N], mark[N];
Edge e[N];
vector<int> ans[N], save[N];

int root(int u) {
	// cerr << u << '\n';
	if (lab[u] < 0) return u;
	else return lab[u] = root(lab[u]);
}

void join(int u, int v) {
	// cerr << u << ' ' << v << '\n';
	u = root(u);
	// cerr << u << ' ';
	v = root(v);
	if (u == v) return;
	// cerr << v << '\n';
	if (lab[u] < lab[v]) {
		lab[v] = u;
	} else {
		lab[v] -= lab[u] == lab[v];
		lab[u] = v;
	}
}

int main() {
	srand(time(NULL));
	double Time = clock();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		e[i] = make_pair(make_pair(x, y), make_pair(c, i));
	}
	long long res = 0;
	int rr = 0;
	while (1) {
		if ((clock() - Time) / CLOCKS_PER_SEC >= 10) break;
		random_shuffle(e + 1, e + m + 1);
		int r = 0;
		long long sum = 0;
		while (1) {
			save[r + 1].clear();
			int cnt = 0;
			memset(lab, -1, sizeof lab);
			for (int i = 1; i <= m; ++ i) {
				if (mark[i] == 0 && root(e[i].first.first) != root(e[i].first.second)) {
					mark[i] = 1;
					cnt ++;
					join(e[i].first.first, e[i].first.second);
					ans[r + 1].push_back(e[i].second.second);
					sum += e[i].second.first;
				}
			}
			if (cnt == n - 1) r ++;
			else break;
		}
		if (sum > res) {
			rr = r;
			res = sum;
			for (int i = 1; i <= r; ++ i) save[i] = ans[i];
		}
		break;
	}
	printf("%d\n", rr);
	for (int i = 1; i <= rr; ++ i) {
		for (int x : save[i]) printf("%d ", x);
		printf("\n");
	}
}