#include <bits/stdc++.h>
using namespace std;

bool in_board(int x, int y) {
	return 1 <= x && x <= 10 && 1 <= y && y <= 10;
}

const int LEN = 12;

int a[LEN][LEN];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++ i) {
		int d, l, r, c;
		cin >> d >> l >> r >> c;
		int u = r + 1, v = c + 1;
		if (d == 0) v = c + l;
		else u = r + l;

		for (int x = r; x < u; ++ x) {
			for (int y = c; y < v; ++ y) {
				if (!in_board(x, y) || a[x][y] == 1) {
					cout << "N";
					return 0;
				}
				a[x][y] = 1;
			}
		}
	}
	cout << "Y";
}