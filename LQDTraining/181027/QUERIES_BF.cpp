#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

const int N = 2005;
const int M = 2e5 + 5;

typedef pair<int, int> ii;

struct Edge {
	int u, v, c;
	Edge(): u(0), v(0), c(0) {}
	Edge(int u, int v, int c): u(u), v(v), c(c) {}
};

int n, m, q;
Edge e[M];
vector<Edge> nonzero;
set<ii> zero;
int lab[N];

int root(int u) {
	if (lab[u] == -1) return u;
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
	freopen("QUERIES.inp", "r", stdin);
	freopen("QUERIES.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++ i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		e[i] = Edge(u, v, c);
	}

	// Kruskal
	sort(e + 1, e + m + 1, [](Edge a, Edge b) {
		return a.c < b.c;
	});
	memset(lab, -1, sizeof lab);
	for (int i = 1; i <= m; ++ i) {
		if (root(e[i].u) != root(e[i].v)) {
			merge(e[i].u, e[i].v);
			nonzero.push_back(e[i]);
		}
	}

	// Answer queries
	for (int i = 1; i <= q; ++ i) {
		int query;
		scanf("%d", &query);
		if (query == 3) {
			printf("%lld\n", mst());
		} else {
			int u, v, c;
			scanf("%d%d", &u, &v);
			if (u > v) swap(u, v);
			if (query == 1) zero.insert(mp(u, v));
			else {
				zero.erase(mp(u, v));
			}
		}
	}
}