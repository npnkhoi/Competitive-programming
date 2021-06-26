#include <bits/stdc++.h>
using namespace std;

int tc, n, k, x[2], dir[2], next_x[2];
vector<pair<int, int>> boucing_points;

int next_point(int dimension) {
	return (dir[dimension] == -1 ? 0 : n);
}

void bounce(int dim) {
	x[dim ^ 1] += dir[dim ^ 1] * abs(x[dim] - next_x[dim]);
	x[dim] = next_x[dim];
	dir[dim] = -dir[dim];
}


int main() {
	cin >> tc;
	while (tc --) {
		boucing_points.clear();
		
		cin >> n >> k >> x[0] >> x[1];

		if (x[0] == x[1]) {
			cout << n << ' ' << n << '\n';
			continue;
		}

		dir[0] = dir[1] = 1;

		for (int i = 0; i < 4; ++ i) {
			next_x[0] = next_point(0);
			next_x[1] = next_point(1);
			if (abs(x[0] - next_x[0]) < abs(x[1] - next_x[1])) {
				bounce(0);
			} else {
				bounce(1);
			}
			boucing_points.push_back({x[0], x[1]});
		}
		k = (k - 1) % 4;
		cout << boucing_points[k].first << ' ' << boucing_points[k].second << '\n';
	}
}