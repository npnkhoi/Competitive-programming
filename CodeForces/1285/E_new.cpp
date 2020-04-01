#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int tc, n;
int diff[N];
set<int> cur_seg;
map<int, int> start;
vector<pair<int, pair<int, int>>> v;

int main() {
	freopen("test.inp", "r", stdin);
	cin >> tc;
	// cerr << tc << '\n';
	while (tc --) {
		// reset datasets
		start.clear();
		v.clear();

		// input
		cin >> n;
		int l, r;
		for (int i = 0; i < n; ++ i) {
			cin >> l >> r;
			// cerr << l << r << '\n';
			v.push_back({l, {-1, i}});
			v.push_back({r, {+1, i}});
		}


		// count increasing
		sort(v.begin(), v.end());
		// cerr << "v: ";
		// for (int i = 0; i < v.size(); ++i) {
		// 	cerr << v[i].first << ' ';
		// }
		// cerr << '\n';
		for (auto p : v) {
			// cerr << "here\n";
			if (p.second.first == -1) {
				// This is left end
				if (cur_seg.empty()) {
					if (start.find(p.first) != start.end()) {
						start[p.first] = -1;
					} else start[p.first] = p.second.second;
				} else if ((int) cur_seg.size() == 1) {
					diff[*cur_seg.begin()] ++;
				}
				cur_seg.insert(p.second.second);
				// printf("When starting seg %d, there is already %d\n", p.second.first, (int) cur_seg.size());
			} else {
				// printf("Seg %d is leaving\n", p.second.first);
				cur_seg.erase(p.second.second);
			}
		}
		// for (int i = 0; i < n; ++i) {
		// 	cerr << diff[i] << ' ';
		// }
		// cerr << '\n';
		for (map<int, int>::iterator it = start.begin(); it != start.end(); ++it) {
			if (it -> second != -1) {
				diff[it -> second] --;
			}
		}
		int res = -n;
		// cerr << res << '\n';
		for (int i = 0; i < n; ++ i) {
			res = max(res, diff[i]);
		}
		res += start.size();
		// cerr << res <<'\n';
		cout << res << '\n';
	}
	return 0;
}