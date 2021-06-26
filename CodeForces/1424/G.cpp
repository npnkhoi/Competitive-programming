#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, +1});
		v.push_back({y, -1});
	}
	sort(v.begin(), v.end());
	int max_alive = 0, cnt_alive = 0, year_max;
	for (auto point : v) {
		cnt_alive += point.second;
		if (cnt_alive > max_alive) {
			max_alive = cnt_alive;
			year_max = point.first;
		}
	}
	cout << year_max << ' ' << max_alive;
}