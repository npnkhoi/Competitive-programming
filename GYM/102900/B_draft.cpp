#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int a[20][20], m, n, k;

bool inBoard(int x, int y) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

int main() {
	cin >> m >> n;
	for (int k = 0; k <= m * n * 8; ++ k) {
		cout << "---- K = " << k << '\n';
		for (int mask = 0; mask < 1 << (m * n); ++ mask) {
			int cnt = 0;
			for (int i = 0; i < m; ++ i) {
				for (int j = 0; j < n; ++ j) {
					a[i][j] = (mask >> (i * n + j)) & 1;
					// cout << (a[i][j] ? 'X' : '.');

				}
				// cout << '\n';
			}
			for (int i = 0; i < m; ++ i) {
				for (int j = 0; j < n; ++ j) {
					for (int dir = 0; dir < 8; ++ dir) {
						int u = i + dx[dir], v = j + dy[dir];
						if (inBoard(u, v) && a[i][j] ^ a[u][v]) {
							cnt ++;
						}
					}
				}
			}
			if (cnt / 2 == k) {
				for (int i = 0; i < m; ++ i) {
					for (int j = 0; j < n; ++ j) {
						cout << (a[i][j] ? 'X' : '.');

					}
					cout << '\n';
				}
				cout << endl;
			}
		}
	} 
}