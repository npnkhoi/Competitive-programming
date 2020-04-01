#include <bits/stdc++.h>
using namespace std;

const int TYPES = 19, N = 83;

const vector<vector<pair<int, int>>> pieces = {
	{{1, 0}, {2, 0}, {3, 0}},
	{{0, 1}, {0, 2}, {0, 3}},
	{{0, 1}, {1, 0}, {1, 1}},
	{{1, 0}, {1, -1}, {1, -2}},
	{{1, 0}, {2, 0}, {2, 1}},
	{{1, 0}, {0, 1}, {0, 2}},
	{{0, 1}, {1, 1}, {2, 1}},
	{{1, -1}, {1, 0}, {0, 1}},
	{{1, 0}, {1, 1}, {2, 1}},
	{{0, 1}, {1, 1}, {1, 2}},
	{{1, 0}, {1, -1}, {2, -1}},
	{{1, 0}, {1, 1}, {1, 2}},
	{{1, 0}, {2, 0}, {2, -1}},
	{{0, 1}, {0, 2}, {1, 2}},
	{{1, 0}, {2, 0}, {0, 1}},
	{{1, -1}, {1, 0}, {1, 1}},
	{{1, 0}, {1, 1}, {2, 0}},
	{{1, 0}, {2, 0}, {1, -1}},
	{{0, 1}, {0, 2}, {1, 1}},
};
const vector<int> id = {0, 0, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6};

int width, res;
int board[N][N], row[N];
vector<int> cnt;

bool check(int type, int x, int y) {
	if (cnt[id[type]] == 0) return false;
	for (int i = 0; i < 3; ++ i) {
		int new_x = x + pieces[type][i].first;
		int new_y = y + pieces[type][i].second;
		if (new_y < 0 || width <= new_y || board[new_x][new_y] == 1) return false;
	}
	return true;
}

void back_track(int x, int y) {
	bool ok = false;
	for (int type = 0; type < TYPES; ++type) {
		if (!check(type, x, y)) continue;
		ok = true;
		// fill the board + decrease cnt
		board[x][y] = 1;
		board[x + pieces[type][0].first][y + pieces[type][0].second] = 1;
		board[x + pieces[type][1].first][y + pieces[type][1].second] = 1;
		board[x + pieces[type][2].first][y + pieces[type][2].second] = 1;
		row[x] ++;
		row[x + pieces[type][0].first] ++;
		row[x + pieces[type][1].first] ++;
		row[x + pieces[type][2].first] ++;
		cnt[id[type]] --;
		
		// get new (x, y)
		int new_x = x,  new_y = y;
		while (board[new_x][new_y]) {
			if (new_y + 1 < width) new_y ++;
			else {
				new_x ++;
				new_y = 0;

				// check result
				for (int very_new_x = new_x;; very_new_x ++) {
					if (row[very_new_x] == width) continue;
					if (row[very_new_x] == 0) {
						res = max(res, width * very_new_x);
					}
					break;
				}
			}
		}

		back_track(new_x, new_y);

		// unfill the board
		board[x][y] = 0;
		board[x + pieces[type][0].first][y + pieces[type][0].second] = 0;
		board[x + pieces[type][1].first][y + pieces[type][1].second] = 0;
		board[x + pieces[type][2].first][y + pieces[type][2].second] = 0;
		row[x] --;
		row[x + pieces[type][0].first] --;
		row[x + pieces[type][1].first] --;
		row[x + pieces[type][2].first] --;
		cnt[id[type]] ++;
	}
}

int findLargestRectangle(std::vector<int> blockNumber) {
	cnt = blockNumber;
	int s_max = (int) blockNumber.size() * 4;
	for (width = 1; width <= sqrt(s_max); ++ width) {
		back_track(0, 0);
	}
	return res;
}

int main() {
	cerr << findLargestRectangle({0, 0, 0, 0, 0, 2, 0});
}