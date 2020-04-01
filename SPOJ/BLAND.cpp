#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int oo = 1e9 + 7;

int m, n, k, res;
int a[N][N], colMin[N], colMax[N], lo[N], hi[N], f[N];
deque<int> qMin, qMax;

void calc(int m, int n) {
	memset(lo, 0, sizeof lo);
	memset(hi, 0, sizeof hi);
	for (int x = 1; x <= m; ++ x) {
		// init
		for (int i = 1; i <= n; ++ i) {
			colMin[i] = oo;
			colMax[i] = -oo;
		}

		for (int y = x; y <= m; ++ y) {
			while (!qMin.empty()) qMin.pop_back();
			while (!qMax.empty()) qMax.pop_back();
			// cerr << "x y: " << x << " " << y << "\n";
			f[0] = 1; 
			for (int i = 1; i <= n; i ++) {
				colMin[i] = min(colMin[i], a[y][i]);
				colMax[i] = max(colMax[i], a[y][i]);
				// cerr << "new col: " << i << " " << colMin[i] << " " << colMax[i] << "\n";

				while (!qMin.empty() && colMin[qMin.back()] > colMin[i]) {
					qMin.pop_back();
					// cerr << "min pop back\n";
				}
				qMin.push_back(i);
				while (!qMax.empty() && colMax[qMax.back()] < colMax[i]) {
					qMax.pop_back();
					// cerr << "max pop back\n";
				}
				qMax.push_back(i);

				f[i] = f[i-1];

				// cerr << "before dead while loop\n";

				while (colMax[qMax.front()] - colMin[qMin.front()] > k) {
					// cerr << qMax.front() << " " << qMin.front() << " " << colMax[qMax.front()] - colMin[qMin.front()] << "\n"; 	
					if (qMax.front() == f[i]) {
						qMax.pop_front();
						// cerr << "max pop front\n";
					}
					if (qMin.front() == f[i]) {
						qMin.pop_front();
						// cerr << "min pop front\n";
					}
					++ f[i];
					if (f[i] > i) break;
				}
				lo[x] = max(lo[x], (y - x + 1) * (i - f[i] + 1));
				hi[y] = max(hi[y], (y - x + 1) * (i - f[i] + 1));
				// cerr << "xyif[i] " << x << " " << y << " " << i  << " " << f[i] << "\n";
			}
		}
	}
	for (int i = 2; i <= m; ++ i) {
		hi[i] = max(hi[i], hi[i - 1]);
	}
	for (int i = m - 1; i >= 1; -- i) {
		lo[i] = max(lo[i], lo[i + 1]);
	}
	// for (int i = 1; i <= m; i ++) {
	// 	cerr << lo[i] << "  " << hi[i] << "\n";
	// }
	for (int i = 1; i < m; ++ i) {
		res = max(res, hi[i] + lo[i + 1]);
	}
}

int main() {
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
		}
	}
	calc(m, n);
	// cerr << "ok\n";
	for (int i = 1; i <= max(m, n); ++ i) {
		for (int j = i + 1; j <= max(m, n); ++ j) {
			swap(a[i][j], a[j][i]);
		}
	}
	// cerr << res << "\n";
	calc(n, m);
	printf("%d", res);
}