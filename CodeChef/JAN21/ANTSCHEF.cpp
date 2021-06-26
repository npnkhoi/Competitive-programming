#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> ant[N][2];
vector<bool> is_straight[N][2];
map<int, int> cnt;
int m[N], idx[2], straight[2], total_straight[2];

int count_collide(int line, int dir) {
	// printf("counting for %d %d (x = %d)\n", line, dir, ant[line][dir][idx[dir]]);
	int other_dir = dir ^  1, ret = 0;
	
	if (!is_straight[line][dir][idx[dir]]) {
		// turning ant
		ret += idx[dir] - straight[dir];
		// cerr << ret << endl;
		ret += straight[other_dir];
		// cerr << ret << endl;
		ret += ant[line][dir].size() - idx[dir] - 1;
	} else {
		// straight ant
		ret += idx[dir] - straight[dir];
		// cerr << ret << endl;
		ret += total_straight[other_dir];
		// cerr << ret << endl;
		ret += (ant[line][other_dir].size() - total_straight[other_dir]) - (idx[other_dir] - straight[other_dir]);
		// printf("other's total straigh = %d\n", total_straight[other_dir]);
		straight[dir] ++;
	}
	idx[dir] ++;

	// printf("result = %d\n", ret);
	return ret;
}

int main() {
	int tc; cin >> tc;
	while (tc --) {
		int n; cin >> n;
		long long res = 0;
		cnt.clear();
		
		// input
		for (int i = 0; i < n; ++ i) {
			ant[i][0].clear();
			ant[i][1].clear();

			cin >> m[i];
			for (int j = 0; j < m[i]; ++ j) {
				int x; cin >> x;
				if (x < 0) {
					ant[i][0].push_back(-x);
				} else {
					ant[i][1].push_back(x);
				}
				cnt[abs(x)] ++;
			}
			sort(ant[i][0].begin(), ant[i][0].end());
			sort(ant[i][1].begin(), ant[i][1].end());
		}
		// process
		for (int i = 0; i < n; ++ i) {
			for (int dir = 0; dir < 2; ++ dir) {
				is_straight[i][dir].clear();
				idx[dir] = straight[dir] = total_straight[dir] = 0;

				for (int x : ant[i][dir]) {
					if (cnt[x] == 1) {
						is_straight[i][dir].push_back(true);
						total_straight[dir] ++;
					} else {
						is_straight[i][dir].push_back(false);
					}
				}
			}

			while (idx[0] < ant[i][0].size() || idx[1] < ant[i][1].size()) {
				if (idx[1] >= ant[i][1].size()) {
					res += count_collide(i, 0);
				} else if (idx[0] >= ant[i][0].size()) {
					res += count_collide(i, 1);
				} else if (ant[i][0][idx[0]] <= ant[i][1][idx[1]]) {
					res += count_collide(i, 0);
				} else {
					res += count_collide(i, 1);
				}
			}
			// printf("res after line %d: %lld\n", i, res);
		}

		res /= 2;

		for (auto x : cnt) {
			if (x.second >= 2) {
				res ++;
			}
		}
		cout << res << '\n';
	}
}