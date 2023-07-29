#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N][N], dp[N][N], n_rows, n_cols;

int main() {
	cin >> n_rows >> n_cols;
	for (int i = 0; i < n_rows; ++ i) {
		for (int j = 0; j < n_cols; ++ j) {
			cin >> a[i][j];
		}
	}

	// Base cases
	dp[0][0] = a[0][0];
	for (int j = 1; j < n_cols; ++ j) {
		dp[0][j] = dp[0][j - 1] + a[0][j];
	}
	for (int i = 1; i < n_rows; ++ i) {
		dp[i][0] = dp[i - 1][0] + a[i][0];
	}

	// Transitions
	for (int i = 1; i < n_rows; ++ i) {
		for (int j = 1; j < n_cols; ++ j) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
		}
	}

	// Result
	cout << dp[n_rows - 1][n_cols - 1];
}