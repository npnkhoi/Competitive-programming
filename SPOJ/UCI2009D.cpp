#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX_SIZE = 8;

vector<unsigned long long> patterns;
vector<int> current_pattern;
set<pair<int, int>> current_cells;
string game_map[MAX_SIZE];
int map_size;

bool getBit(unsigned long long mask, int pos) {
	// Note:
	// - "a >> b" means "a * (2 ^ b)"
	// - "a << b" means "a div (2 ^ b)"
	return mask >> pos & 1;
}

void print_pattern(unsigned long long x) {
	for (int i = 0; i < 8; ++ i) {
		for (int j = 0; j < 8; ++ j) {
			cerr << getBit(x, i * 8 + j) << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
}

unsigned long long get_hash(vector<int> pat) {
	// Find min row, min col
	int min_row = 0, min_col = 0;
	for (auto cell : current_cells) {
		min_row = min(min_row, cell.first);
		min_col = min(min_col, cell.second);
	}
	// Shift the cells, embed to result ("bitmask" technique)
	unsigned long long result = 0;
	for (auto cell : current_cells) {
		result |= (1LL << ((cell.first - min_row) * 8 + cell.second - min_col));
	}
	return result;
}

void backtrack(int row, int col) {
	// marking (1)
	current_cells.insert({row, col});

	if (current_cells.size() == 8) {
		// Compare with existing patterns
		unsigned long long current_hash = get_hash(current_pattern);

		// check if the pattern is created already
		bool overlap = false;
		for (auto old_pattern : patterns) {
			if (old_pattern == current_hash) {
				overlap = true;
				break;
			}
		}

		// save new pattern
		if (!overlap) patterns.push_back(current_hash);

	} else {	
		for (int dir = 0; dir < 4; ++ dir) {
			int new_row = row + dx[dir];
			int new_col = col + dy[dir];

			// check if the new cell is visited
			if (current_cells.find({new_row, new_col}) != current_cells.end()) {
				continue;
			}

			current_pattern.push_back(dir); // marking (2)
			backtrack(new_row, new_col);
			current_pattern.pop_back(); // unmarking (2)
		}
	}
	// unmarking (1)
	current_cells.erase({row, col});
}

void generate_patterns() {
	backtrack(0, 0);
}

bool check(int row, int col, unsigned long long pattern) {
	for (int i = 0; i < 8; ++ i) {
		for (int j = 0; j < 8; ++ j) {
			if (getBit(pattern, i * 8 + j)) {
				if (row + i >= map_size || col + j >= map_size) {
					return false;
				}
				if (game_map[row + i][col + j] == '.') {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	generate_patterns();
	int test_case;
	cin >> test_case;
	while (test_case --) {
		// Solve the test
		cin >> map_size;
		for (int i = 0; i < map_size; ++ i) {
			cin >> game_map[i];
		}
		int count_octaves = 0;
		for (int row = 0; row < map_size; ++ row) {
			for (int col = 0; col < map_size; ++ col) {
				for (auto pattern : patterns) {
					count_octaves += check(row, col, pattern);
				}
			}
		}
		cout << count_octaves << '\n';
	}
}