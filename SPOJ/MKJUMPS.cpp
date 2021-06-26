#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int dy[] = {-1, +1, -2, +2, -2, +2, -1, +1};
const int N_DIR = 8;
const int N_ROW = 15;

int n_row, indent[N_ROW], len[N_ROW], mark[N_ROW][N_ROW];
int count_unvisited;

bool inBoard(int row, int col) {
	return row >= 0 && row < n_row && col >= indent[row] && col < indent[row] + len[row];
}

void dfs(int row, int col) {
	mark[row][col - indent[row]] = 1;
	count_unvisited --;

	for (int dir = 0; dir < N_DIR; ++ dir) {
		int new_row = row + dx[dir];
		int new_col = col + dy[dir];
		if (!inBoard(new_row, new_col) || mark[new_row][new_col - indent[new_row]]) {
			continue;
		}
		dfs(new_row, new_col);
	}
}

int main() {
	int case_index = 0;
	while (cin >> n_row) {
		if (n_row == 0) {
			break;
		}

		// Update global values
		case_index ++;
		memset(mark, 0, sizeof mark);
		count_unvisited = 0;

		// Input
		for (int i = 0; i < n_row; ++ i) {
			cin >> indent[i] >> len[i];
			count_unvisited += len[i];
			// indent[0] = 0;
			if (i > 0) {
				indent[i] += indent[i - 1];
			} else {
				indent[0] = 0;
			}
		}
		
		// Call backtracking (DFS)
		dfs(0, 0);

		// Output
		if (count_unvisited == 1) 
			printf("Case %d, %d square can not be reached.\n", case_index, count_unvisited);
		else 
			printf("Case %d, %d squares can not be reached.\n", case_index, count_unvisited);
	}
}