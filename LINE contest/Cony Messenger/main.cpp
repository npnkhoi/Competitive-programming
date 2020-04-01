#include <bits/stdc++.h>
using namespace std;

unsigned long long get_hash(string &s) {
	unsigned long long ret = 0;
	for (char ch : s) {
		ret = ret * BASE + ch;
	}
	return ret;
}

int find_pos(unsigned long long val) {
	int l = 0, r = v.size() - 1, bs = 0;
	while (l <= r) {
		int mid = (l+r)/2;
		if (v[mid].first <= val) {
			bs = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; ++ i) {
		cin >> ori[i];
		for (int i = 1;)
		v.push_back({get_hash(ori[i]), i});
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++ i) {
		cin >> com[i];
		unsigned long long hash = get_hash(com[i]);
		int pos = find_pos(hash);
		while (pos < v.size() && v[pos].first == hash) {
			if (ori[v[pos].second] == com[i])
		}
	}
}