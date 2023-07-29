#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 1, 1};
const int dy[] = {1, 1, 0, -1};
const int L = 42, CHAR = 26, N = 22;

int l, c, n, cnt[N][CHAR], cnt_tmp[CHAR];
string word[N], board[L];
long long in_word[L][L];

bool in_board(int x, int y) {
	return 0 <= x && x < l && 0 <= y && y < c;
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < l; ++ i) {
		cin >> board[i];
	}
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> word[i];
		for (auto c : word[i]) {
			cnt[i][c - 'A'] ++;
		}
	}
	for (int row = 0; row < l; ++ row) {
		for (int col = 0; col < c; ++ col) {
			// printf("scanning cell %d %d\n", row, col);
			for (int word_id = 0; word_id < n; ++ word_id) {
				if (cnt[word_id][board[row][col] - 'A'] == 0) continue;
				int len = word[word_id].size();
				for (int dir = 0; dir < 4; ++ dir) {
					// printf("dir = %d\n", dir);
					int end_row = row + (len - 1) * dx[dir];
					int end_col = col + (len - 1) * dy[dir];
					// printf("end cell: %d %d\n", end_row, end_col);
					if (!in_board(end_row, end_col))
						continue;
					memset(cnt_tmp, 0, sizeof cnt_tmp);
					// cerr << "check 0\n";
					for (int i = 0; i < len; ++ i) {
						int row_tmp = row + i * dx[dir];
						int col_tmp = col + i * dy[dir];
						// printf("cell tmp: %d %d (char = %d)\n", row_tmp, col_tmp, board[row_tmp][col_tmp] - 'A');
						// cerr << board[row_tmp][col_tmp] << '\n';
						cnt_tmp[board[row_tmp][col_tmp] - 'A'] ++;
						// cerr << "done that cell.\n";
					}
					// cerr << "check 1\n";
					bool ok = true;
					for (int c = 0; c < CHAR; ++ c) {
						if (cnt_tmp[c] != cnt[word_id][c]) {
							ok = false;
						}
					}
					if (!ok) continue;
					// cerr << "check 2\n";
					// cerr << "matched!\n";
					for (int i = 0; i < len; ++ i) {
						int row_tmp = row + i * dx[dir];
						int col_tmp = col + i * dy[dir];
						in_word[row_tmp][col_tmp] |= (1LL << word_id);
					}
				}
			}
		}
	}
	int res = 0;
	for (int row = 0; row < l; ++ row) {
		for (int col = 0; col < c; ++ col) {
			if (__builtin_popcountll(in_word[row][col]) >= 2) {
				res ++;
			}
		}
	}
	cout << res;
}