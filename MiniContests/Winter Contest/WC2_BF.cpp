#include <bits/stdc++.h>
using namespace std;

int countFactor(int x) {
	int res = 0;
	for (int i = 1; i <= sqrt(x); i ++) {
		if (x % i == 0) res += 2;
	}
	int tmp = (int) sqrt(x);
	res -= (tmp * tmp == x);
	return res;
}

int ans(int x) {
	for (int i = 1; i <= 2e6; i ++) {
		if (countFactor(i) == x) return i;
	}
}

int main() {
	int tmp = 1;
	for (int val = 0; val <= 9; val ++) {
		cerr << val << " " << ans(tmp) << "\n";
		tmp *= 2;
	}
}