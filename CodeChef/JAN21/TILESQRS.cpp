#include <bits/stdc++.h>
using namespace std;

const vector<int> trans[] = {
	{0},
	{0, 1, 0},
	{1, 0, 2, 0, 1, 0, 2}
};
const int N = 202;

typedef pair<int, int> Cell;
typedef vector<Cell> CellList;

int tc, n, q, cnt_squares, board[N][N], cnt_queries;
CellList cl;

vector<vector<int>> answer = {
	{0, 1, 0},
	{1, 0, 0},
	{1, 0, 0}
};

int query(int x, int y) {
	// return the number of squares
	cout << "1 " << x+1 << ' ' << y+1 << endl;
	
	// for OJ
	string ans;
	cin >> ans;
	int delta = stoi(ans) - cnt_squares;
	cnt_squares = stoi(ans);
	
	// for debugging
	// cnt_queries ++;
	// int res = 0;
	// answer[x][y] ^= 1;
	// for (int i = 0; i+1 < n; ++ i) {
	// 	for (int j = 0; j+1 < n; ++ j) {
	// 		int ok = true;
	// 		for (int mask = 0; mask < 4; ++ mask) {
	// 			int dx = mask & 1, dy = mask >> 1;
	// 			if (answer[i + dx][j + dy] != (dx ^ dy)) {
	// 				ok = false;
	// 			}
	// 		}
	// 		res += ok;
	// 	}
	// }
	// cerr << "query answer: " << res << endl;
	// int delta = res - cnt_squares;
	// cnt_squares = res;

	// end of splitting
	return delta;
}

void stamp(int base_row, int base_col) {
	board[base_row][base_col] = 0;
	board[base_row + 1][base_col] = 1;
	board[base_row][base_col + 1] = 1;
	board[base_row + 1][base_col + 1] = 0;
}

void bruteForce(vector<Cell> &cells, int shift, int base_row, int base_col) {
	// conduct query chain for any set of cells (size 3 or 4)
	int sz = cells.size();
	int delta;
	int trans_index = 0;
	while (true) {
		delta = query(cells.back().first, cells.back().second);
		if (abs(delta) == shift) {
			break;
		}
		int change_id = trans[sz - 2][trans_index];
		query(cells[change_id].first, cells[change_id].second);
		trans_index ++;
	}

	stamp(base_row, base_col);
	board[cells.back().first][cells.back().second] ^= (delta < 0);
}

void solveTopLeft() {
	// cerr << "solving top left\n";
	for (int row = 0; row+1 < n; row += 2) {
		for (int col = 0; col+1 < n; col += 2) {
			int shift = (row == 0 || col == 0 ? 1 : 2);
			cl = {{row+1, col}, {row+1, col+1}, {row, col+1}, {row, col}};
			bruteForce(cl, shift, row, col);
			// cerr << "done brute force for " << row << ' ' << col << '\n';	
		}
	}
}

void solveRemaining() {
	// solve corner (2)
	// cerr << "solving corner\n";
	cl = {{n-2, n-1}, {n-1, n-2}, {n-1, n-1}};
	bruteForce(cl, 1, n-2, n-2);

	// solve edges (3)
	// cerr << "changing edges\n";
	for (int i = 0; i <= n-3; ++ i) {
		query(n-2, i);
		query(i, n-2);
	}
	query(n-2, n-2);

	// vertical edge
	// cerr << "solving vertical edge\n";
	for (int base_row = 0; base_row+1 < n; base_row += 2) {
		cl = {{base_row, n-1}, {base_row+1, n-1}};
		bruteForce(cl, 1, base_row, n-2);
	}

	// horizontal edge
	// cerr << "solving horizontal edge\n";
	for (int col = 0; col+1 < n; col += 2) {
		cl = {{n-1, col}, {n-1, col+1}};
		bruteForce(cl, 1, n-2, col);
	}
}

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n >> q >> cnt_squares;
		// solve the even sub-square
		solveTopLeft();

		// solve the reamaining edges
		if (n % 2 == 1) {
			solveRemaining();
		}

		// print the board -- answer
		cout << 2 << endl;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		int verdict;
		cin >> verdict;
		// FOR DEBUGGING
		// cerr << "Cnt querries: " << cnt_queries << "\n";
		// cnt_queries = 0;
		// cerr << "Answer:\n";
		// for (int i = 0; i < n; ++ i) {
		// 	for (int j = 0; j < n; ++ j) {
		// 		cout << answer[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
	}
}