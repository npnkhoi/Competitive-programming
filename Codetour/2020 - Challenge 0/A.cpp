#include <bits/stdc++.h>
using namespace std;

const int N = 405;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, k, a[N][N], res, reward, regions, mark[N][N], cnt[N*N], sum_region[N*N];

bool inBoard(int row, int col) {
	return 0 <= row && row < n && 0 <= col && col < n;
}

void update(int row, int col, int type) {
	if (!inBoard(row, col)) return;
	int id = mark[row][col];
	if (type == +1 && cnt[id] == 0) {
		reward += sum_region[id];
	} else if (type == -1 && cnt[id] == 1) {
		reward -= sum_region[id];
	}
	cnt[id] += type;
}

void update(int row_up, int row_down, int col_left, int col_right, int type) {
	for (int i = row_up; i <= row_down; ++ i) {
		for (int j = col_left; j <= col_right; ++ j) {
			update(i, j, type);
		}
	}
}


void dfs(int i, int j, int id) {
	mark[i][j] = id;
	sum_region[id] += a[i][j];
	for (int dir = 0; dir < 4; ++ dir) {
		int u = i + dx[dir], v = j + dy[dir];
		if (inBoard(u, v) && mark[u][v] == -1 && a[u][v] != -1) {
			dfs(u, v, id);
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			cin >> a[i][j];
		}
	}
	memset(mark, -1, sizeof mark);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			if (mark[i][j] == -1 && a[i][j] != -1) {
				dfs(i, j, regions);
				// printf("cell (%d, %d) => sum: %d\n", i, j, sum_region[regions]);
				regions ++;
			}
		}
	}
	for (int upper_row = 0; upper_row < n - k + 1; ++ upper_row) {
		memset(cnt, 0, sizeof cnt);
		reward = 0;
		int lower_row = upper_row + k - 1;

		update(upper_row - 1, lower_row + 1, 0, k-1, +1);
		update(upper_row, lower_row, k, k, +1);

		res = max(res, reward);

		for (int left_col = 1; left_col < n - k + 1; ++ left_col) {
			update(upper_row, lower_row, left_col - 2, left_col - 2, -1);
			update(upper_row - 1, left_col - 1, -1);
			update(lower_row + 1, left_col - 1, -1);

			update(upper_row, lower_row, left_col + k, left_col + k, +1);
			update(upper_row - 1, left_col + k - 1, +1);
			update(lower_row + 1, left_col + k - 1, +1);

			res = max(res, reward);
		}
	}
	cout << res;
}