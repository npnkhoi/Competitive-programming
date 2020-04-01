#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int tc, n;
int diff[N];
set<int> cur_seg;
map<int, int> start;
vector<pair<int, pair<int, int>>> v;

int main() {
	cin >> tc;
	while (tc --) {
		// input
		cin >> n;
		int l, r;
		for (int i = 0; i < n; ++ i) {
			cin >> l >> r;
			v.push_back({l, {-1, i}});
			v.push_back({r, {+1, i}});
		}

		// reset datasets
		start.clear();
		v.clear();

		// count increasing
		sort(v.begin(), v.end());
		for (auto p : v) {
			if (p.second.second == -1) {
				// This is left end
				if (cur_seg.empty()) {
					if (start.find(p.first) != start.end()) {
						start[p.first] = -1;
					} else start[p.first] = p.second.first;
				} else if ((int) cur_seg.size() == 1) {
					diff[*cur_seg.begin()] ++;
				}
				cur_seg.insert(p.second.first);
			} else {
				cur_seg.erase(p.second.first);
			}
		}
		for (map<int, int>::iterator it = start.begin(); it != start.end(); ++it) {
			if (it -> second != -1) {
				diff[it -> second] --;
			}
		}
		int res = -n;
		for (int i = 0; i < n; ++ i) {
			res = max(res, diff[i]);
		}
		res += start.size();
		cout << 3 << '\n';
	}
	return 0;
}