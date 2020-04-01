#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, m, res;
int lab[N];
vector<pair<int, int> > tmp;

int root(int u) {
	if (lab[u] < 0) return u;
	else return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
	u = root(u), v = root(v);
	if (lab[u] < lab[v]) {
		lab[v] = u;
	} else {
		lab[u] = v;
		lab[v] -= (lab[u] == lab[v]);
	}
}

int main() {
	freopen("BL6.inp", "r", stdin);
	freopen("BL6.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(lab, -1, sizeof lab);
	for (int i = 1; i <= m; ++ i) {
		int u, v, type;
		scanf("%d%d%d", &u, &v, &type);
		if (type == 1) {
			tmp.push_back(make_pair(u, v));
		} else {
			if (root(u) != root(v)) merge(u, v);
		}
	}
	for (int i = 0; i < tmp.size(); ++ i) {
		int u = tmp[i].first, v = tmp[i].second;
		if (root(u) == root(v)) {
			res ++;
		} else {
			merge(u, v);
		}
	}
	printf("%d", res);
}