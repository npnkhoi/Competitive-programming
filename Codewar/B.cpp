#include <bits/stdc++.h>
using namespace std;

long long nonOverlappingArea(std::vector<int> a, std::vector<int> b) {
	// if (a[0] > a[2]) swap(a[0], a[2]);
	// if (a[1] > a[3]) swap(a[1], a[3]);
	// if (b[0] > b[2]) swap(b[0], b[2]);
	// if (b[1] > b[3]) swap(b[1], b[3]);

	long long x, y;

	x = max(0, min(a[2], b[2]) - max(a[0], b[0]));
	y = max(0, min(a[3], b[3]) - max(a[1], b[1]));

	return 1LL * (a[2] - a[0]) * (a[3] - a[1]) + 1LL * (b[2] - b[0]) * (b[3] - b[1]) - 2LL * x * y;
}

int main() {
	cerr << nonOverlappingArea({-2, -1, 3, 3}, {2, -2, 6, 4});
}
