// unfinished, because I find it's easy
#include <bits/stdc++.h>
using namespace std;

void flood(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	id[x][y] = idx;

	while (!q.empty()) {

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			if (a[i][j] == '#' && id[i][j] = 0) {
				idx ++;
				flood(i, j);
			}
		}
	}
}