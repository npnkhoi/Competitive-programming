#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int x[N], y[N];
double sum_len[N];

long long sqr(int x) {
	return x * x;
}

double dist(int i, int j) {
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

int ccw(int a, int b, int c) {
	long long tmp = (x[b] - x[a]) * (y[c] - y[b]) - (y[b] - y[a]) * (x[c] - x[b]);
	if (tmp == 0) return 0;
	if (tmp > 0) return 1;
	return -1;
}
 
bool intersect(int a, int b, int c, int d) {
	return (ccw(a, b, c) * ccw(a, b, d) <= 0) && (ccw(c, d, a) * ccw(c, d, b) <= 0);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i < n; ++ i) {
		sum_len[i] = sum_len[i - 1] + dist(i - 1, i);
	}
	double res = sum_len[n - 1];

	for (int i = 0; i < n - 1; ++ i) {
		for (int j = i + 1; j < n; ++ j) {

			bool ok = true;
			for (int k = 1; k < n; ++ k) {
				if (intersect(i, j, k - 1, k)) {
					// printf("%d %d intersects %d %d\n", i, j, k-1, k);
					if (i != k - 1 && i != k && j != k - 1 && j != k) {
						ok = false;
						// cerr << "make it false.\n";
					}
				}
			}
			if (ok) {
				res = min(res, sum_len[n - 1] - sum_len[j] + sum_len[i] + dist(i, j));
			}
		}
	}
	printf("%.10lf", res);
}