#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
char a[N][N], b[N][N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> b[i][j];
			tot += b[i][j] != a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (tot < n * m / 2) cout << a[i][j];
			else cout << (a[i][j] == 'X' ? '.' : 'X');
		}
		cout << endl; 
	}
}