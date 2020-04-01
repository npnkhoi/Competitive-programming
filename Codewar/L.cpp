#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sys_eqn, e;
int a[7];

void eliminate(int row1, int row2, int col) {
	int lcm = e[row1][col] * e[row2][col] / __gcd(e[row1][col], e[row2][col]);
	int factor_row1 = lcm / e[row1][col], factor_row2 = lcm / e[row2][col];
	for (int i = 0; i <= 6; ++ i) {
		e[row2][i] = e[row1][i] * factor_row1 - e[row2][i] * factor_row2;
	}
}

void show() {
	for (int i = 1; i <= 6; ++ i) {
		for (int j = 0; j <= 6; ++ j) {
			cerr << e[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
}

bool check(int sum) {
	// cerr << "check " << sum << '\n';
	e = sys_eqn;
	e[6][0] = sum;

	// Gauss elimination
	for (int idx = 1; idx <= 6; ++ idx) {
		// cerr << "idx = " << idx << '\n';
		// show();
		// get into diagonal
		if (e[idx][idx] == 0) { 
			bool ok = false;
			for (int row_below = idx + 1; row_below <= 6; ++ row_below) {
				if (e[row_below][idx] != 0) {
					// swap row(idx) and row(row_below)
					for (int col = 0; col <= 6; ++ col) {
						swap(e[idx][col], e[row_below][col]);
					}
					ok = true;
					break;
				}
			}
			if (!ok) continue;
		}

		// eliminate. pivot: e[row][idx] e[idx][idx]
		for (int row = 1; row <= 6; ++ row) {
			
			if (row == idx || e[row][idx] == 0) continue;
			eliminate(idx, row, idx);
		}
	}

	eliminate(5, 4, 6);

	for (int idx = 1; idx <= 6; ++ idx) {
		if (e[idx][idx] == 0) {
			if (e[idx][0] != 0) return false;
		} else {
			if (e[idx][0] % e[idx][idx] != 0) return false;
			a[idx] = e[idx][0] / e[idx][idx];
			if (a[idx] < 0) return false;
		}
	}
	return (a[6] <= a[1] + a[2]);
}

std::vector<int> countStrikeRounds(std::vector<int> kills, std::vector<int> deaths) {
	// init system 
	sys_eqn = {
		{},
		{deaths[0], 					0, 1, 0, 1, 1, 0},
		{deaths[1], 					1, 0, 0, 1, 1, 0},
		{deaths[2], 					1, 1, 1, 0, 0, 0},
		{kills[0] + kills[1], 0, 0, 1, -1, 0, 1},
		{kills[2], 						0, 0, 0, 1, 2, 1},
		{0, 									1, 1, 1, 1, 1, 0}
	};

	int mi = 0, ma = deaths[0] + deaths[1] + deaths[2];
	while (mi <= ma && !check(mi)) ++ mi;
	if (mi > ma) return {};
	while (!check(ma)) -- ma;
	return {mi, ma};
}

int main() {
	vector<int> test = countStrikeRounds({1, 1, 2}, {1, 1, 2});
	for (auto x : test) cerr << x << ' ';	
}
