// algorithm:  meet in the middle (sqrt style)
#include <bits/stdc++.h>
using namespace std;

typedef int Mat[2][2];

const Mat BASE = {0, 1, 1, 1};
const Mat FIB0 = {0, 0, 1, 0};

int tc, md, a, b, L;
Mat fib, base, tmp;
map<pair<int, int>, int> IDRight;

void show(Mat &a) { // for debug
	cerr << "show\n";
	cerr << a[0][0] << " " << a[0][1] << " " << a[1][0] << " " << a[1][1] << "\n";
}

void mul(const Mat &a, const Mat &b, Mat &c, int m, int n, int p) {
	for (int i = 0; i < m; ++ i) {
		for (int j = 0; j < p; ++ j) {
			c[i][j] = 0;
			for (int k = 0; k < n; ++ k) {
				c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % md;
			}
		}
	}
}

void copy(const Mat &a, Mat &b, int m, int n) {
	for (int i = 0; i < m; ++ i) {
		for (int j = 0; j < n; ++ j) {
			b[i][j] = a[i][j];
		}
	}
}

void initLeft() {
 	copy(FIB0, fib, 2, 1);
 	copy(BASE, base, 2, 2);
 	for (int i = 2; i <= L; ++ i) {
 		mul(base, BASE, tmp, 2, 2, 2);
 		copy(tmp, base, 2, 2);
 	}
}

void initRight() {
	IDRight.clear();
	int x = a, y = b;
	for (int i = 0; i < L; ++ i) {
		if (IDRight.find(make_pair(x, y)) == IDRight.end())
			IDRight[make_pair(x, y)] = i;
		int tmp = x;
		x = (y - x + md) % md;
		y = tmp;
	}
}

void meetInTheMiddle() {
	for (int i = 0; i < L; ++ i) {
		if (IDRight.find(make_pair(fib[0][0], fib[1][0])) != IDRight.end()) {
			int res = i * L + IDRight[make_pair(fib[0][0], fib[1][0])];
			printf("%d\n", res);
			return;
		}
		mul(base, fib, tmp, 2, 2, 1);
		copy(tmp, fib, 2, 1);
	}
	printf("-1\n");
}

int main() {
	//freopen("KFIB.inp", "r", stdin);
	//freopen("KFIB.out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d", &md, &a, &b);
		if (md == 1) {
			if (a == 0 && b == 0) printf("0\n");
			else printf("-1\n");
			continue;
		}
		L = (int) ceil(sqrt(6LL * md) + 2);
		// cerr << L << "\n";
		initLeft();
		initRight();
		meetInTheMiddle();
	}
}
