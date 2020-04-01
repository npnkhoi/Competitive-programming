#include <bits/stdc++.h>
using namespace std;

// const int N = 1e3 + 5;

int n, res;
vector<pair<int, int> > v;
set<int> unpin;

int main() {
	// freopen("SEGMENT")
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l > r) swap(l, r);
		v.push_back(make_pair(l, -i));
		v.push_back(make_pair(r, i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 2 * n; ++ i) {
		// cerr << v[i].first << " " << v[i].second << "\n";
		if (v[i].second < 0) {
			unpin.insert(- v[i].second);
		} else {
			if (unpin.find(v[i].second) != unpin.end()) {
				res ++;
				unpin.clear();
			}
		}
	}
	printf("%d", res);
}