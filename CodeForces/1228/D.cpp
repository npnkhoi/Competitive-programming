#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int id[N];
set<pair<int,int> > edges;
vector<int> side_23;
long long size1, size2, size3;


bool same_side(int u, int v) {
	if (u > v) swap(u, v);
	return edges.find({u, v}) == edges.end();
}

void no_way() {
	printf("-1");
	exit(0);
}

void Try() {
	size1 = size2 = 1;
	id[1] = 1; // vtx 1 in set 1
	for (int i = 2; i <= n; ++ i) {
		if (same_side(1, i)) {
			id[i] = 1;
			size1 ++;
		}
		else side_23.push_back(i);
	}
	if (side_23.size() <= 1) no_way();

	id[side_23[0]] = 2;
	for (int i = 1; i < side_23.size(); ++ i) {
		if (same_side(side_23[0], side_23[i])) {
			id[side_23[i]] = 2;
			size2 ++;
		} else {
			id[side_23[i]] = 3;
			size3 ++;
		}
	}
	if (size3 == 0) no_way();
}

void check() {
	if (size1 * size2 + size2 * size3 + size3 * size1 != m) {
		no_way();
	}
	for (auto edge : edges) {
		if (id[edge.first] == id[edge.second]) {
			// cerr << edge.first << ' ' << edge.second << ": wrong edge\n";
			no_way();
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		edges.insert({u, v});
	}

	Try();
	// cerr << "point 1\n";

	// for (int i = 1; i <= n; ++ i) {
	// 	printf("%d ", id[i]);
	// }

	check();
	// cerr << "point 2\n";

	for (int i = 1; i <= n; ++ i) {
		printf("%d ", id[i]);
	}
}