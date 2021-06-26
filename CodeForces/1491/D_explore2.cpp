#include <bits/stdc++.h>
using namespace std;

long long lso(long long x) {
	return x & (-x);
}

bool include(long long u, long long v) {
	return (u & v) == v;
}

bool reachable(long long u, long long v) {
	long long acc_u = u;
	while (u < v) {
		while (u % 2 == 0 && v % 2 == 0) {
			u /= 2;
			v /= 2;
		}
		if (include(acc_u, lso(u ^ v))) {
			u += lso(u ^ v);
		} else if (u % 2 == 1) {
			u += 1;
		} else {
			break;
		}
		acc_u |= u;
	}
	return (u == v) || ((u & v) == u);

}


int main() {
	// for (int i = 1; i <= 100; ++ i) {
	// 	for (int j = 1; j <= i; ++ j) {
	// 		if ((i & j) == j) {
	// 			printf("%d %d ", i, i + j);
	// 			cerr << reachable(i, i+j) << '\n';
	// 		}
	// 	} 
	// }

	for (int i = 1; i <= 20; ++ i) {
		for (int j = i+1; j <= 20; ++ j) {
			if (reachable(i, j)) {
				cout << i << ' ' << j << '\n';
			}
		}
	}
}