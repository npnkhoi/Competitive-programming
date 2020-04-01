#include <bits/stdc++.h>
using namespace std;

const int N = 23;

int n, r, x, y, w, s, c[N][N];
double wi[N], lo[N];

void init() {
	for (int n = 1; n <= 20; ++ n) {
		c[n][0] = c[n][n] = 1;
		for (int k = 1; k < n; ++ k) {
			c[n][k] = c[n - 1][k] + c[n - 1][k - 1];
		}
	}
}

int main() {
	init();
	cin >> n;
	while (n --) {
		cin >> r >> s >> x >> y >> w;
		wi[0] = lo[0] = 1;
		for (int i = 1; i <= y; ++ i) {
			wi[i] = wi[i - 1] * (double) (s - r + 1) / s;
			lo[i] = lo[i - 1] * (double) (r - 1) / s;
		}
		double win_prob = 0;
		for (int i = x; i <= y; ++ i) {
			win_prob += c[y][i] * wi[i] * lo[y - i];
		}
		// cerr << win_prob << ' ';
		if (win_prob * (w - 1) - (1 - win_prob) > 0) cout << "yes\n";
		else cout << "no\n";
	}
}