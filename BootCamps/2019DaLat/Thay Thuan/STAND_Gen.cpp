#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("points.txt", "w", stdout);
	double Time = clock();
	int cnt = 0;
	for (int x = 1; x <= 7000; ++ x) {
		for (int y = 1; y <= 7000; ++ y) {
			if (__gcd(x, y) != 1) continue;
			double tmp = sqrt(x * x + y * y);
			if (floor(tmp) == tmp) {
				cnt ++;
				printf("{%d,%d},", x, y);
			}
		}
	}
	cerr << cnt << "\n";
	cerr << (clock() - Time) / CLOCKS_PER_SEC;
}