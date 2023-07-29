#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 5;
const int N = 1e4 + 5;

vector<long long> vals;
int cnt_people[2 * N];
pair<long long, long long> a[N];

int compressed(long long val) {
	return upper_bound(vals.begin(), vals.end(), val) - vals.begin();
}

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i].first >> a[i].second;
		vals.push_back(a[i].first);
		vals.push_back(a[i].second + 1);
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	int cnt_unique = vals.size();

	for (int i = 0; i < n; ++ i) {
		cnt_people[compressed(a[i].first)] += 1;
		cnt_people[compressed(a[i].second + 1)] -= 1;
	}

	for (int i = 1; i <= cnt_unique; ++ i) {
		cnt_people[i] += cnt_people[i - 1];
	}

	long long res = INF;
	for (int i = 0; i < q; ++ i) {
		long long time, cnt;
		cin >> time >> cnt;
		int true_cnt;
		if (time > vals.back()) {
			true_cnt = 0;
		} else {
			int id = compressed(time);
			if (vals[id - 1] > time) id --;
			true_cnt = cnt_people[id];
		}
		if (true_cnt != cnt) {
			res = min(res, time);
		}
	}
	cout << (res == INF ? -1 : res);
}