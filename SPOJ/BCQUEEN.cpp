#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n, result;
bool mark_col[N], mark_diag1[2*N-1], mark_diag2[2*N-1];

bool can_place(int row, int col) {
	return !(mark_col[col] || mark_diag1[row - col + n - 1] || mark_diag2[row + col]);
}

void backtrack(int row) {
	if (row == n) {
		result ++;
		return;
	}
	for (int col = 0; col < n; ++ col) {
		if (can_place(row, col)) {
			int diag1_index = row - col + n - 1;
			int diag2_index = row + col;

			// mark that case
			mark_col[col] = true;
			mark_diag2[diag2_index] = true;
			mark_diag1[diag1_index] = true;

			// proceed to the next level
			backtrack(row + 1);

			// unmark
			mark_col[col] = false;
			mark_diag1[diag1_index] = false;
			mark_diag2[diag2_index] = false;
		}
	}
}

int main() {
	cin >> n;
	backtrack(0);
	cout << result;
}