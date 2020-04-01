#include <bits/stdc++.h>
using namespace std;

void Input() {
	cin >> n >> q;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i];
	}
	for (int i = 0; i < q; ++ i) {
		cin >> query[i].l1 >> query[i].r1 >> query[i].l2 >> query[i].r2;
	}
}

void Prep() {
	// 1. Ox axis
	// 1.1. Compress coors
	vector<int> id(a, a + n);
	sort(id.begin(), id.end());
	id.resize(unique(id.begin(), id.end()) - id.begin());
	for (int i = 0; i < n; ++ i) {
		a[i] = upper_bound(id.begin(), id.end(), a[i]) - id.begin();
	}
	// 1.2. Get max covering ranges
	map<int, pair<int, int>> range;
	for (int i = 0; i < n; ++ i) {
		int coor = i + 1;
		if (range.find(a[i]) == range.end()) {
			range[a[i]] = {coor, coor};
		} else {
			range[a[i]].second = coor;
		}
	}
	// 1.3. Add to vector 'v'
	for (auto& it : range) {
		v.push_back({})
	}

	// 2. Queries
	for (int i = 0; i < q; ++ i) {
		v.push_back({query[i].l1, -1, i});
		v.push_back({query[i].r1, -1, i});
	}
}

int main() {
	Input();
}