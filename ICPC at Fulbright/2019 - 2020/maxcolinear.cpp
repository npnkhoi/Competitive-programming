// maxcolinear
#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

int n, x[N], y[N];
vector<pair<int, int> > coef;

pair<int, int> simplify(int x, int y) {
	if (y == 0) return {1, 0};
	int gcd = __gcd(abs(x), abs(y));
	if (y < 0) {
		x = -x;
		y = -y;
	}
	return {x / gcd, y / gcd};
}

int main() {
	while (scanf("%d", &n)) {
		for (int i = 0; i < n; ++ i) {
			scanf("%d%d", &x[i], &y[i]);
		}

		if (n == 0) break;
		if (n == 1) {
			printf("1\n");
			continue;
		}

		int res = 2;
		for (int i = 0; i < n; ++ i) {
			coef.clear();
			for (int j = 0; j < n; ++ j) {
				if (j == i) continue;
				coef.push_back(simplify(x[j] - x[i], y[j] - y[i]));
			}
			sort(coef.begin(), coef.end());
			int cnt = 2;
			for (int j = 1; j < n - 1; ++ j) {
				if (coef[j] == coef[j - 1]) {
					cnt ++;
					res = max(res, cnt);
				} else {
					cnt = 2;
				}
			}
		}
		printf("%d\n", res);
	}
}