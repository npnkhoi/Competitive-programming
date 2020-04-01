#include <bits/stdc++.h>
using namespace std;

int countDiv(int val) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(val); ++ i) {
		if (val % i == 0) {
			cnt += 2;
		}
		if (i * i == val) cnt --;
	}
	return cnt;
}

int main() {
	// for (int i = 1; i <= 100; ++ i) {
	// 	for (int val = 1; val <= 1e6; ++ val) {
	// 		if (countDiv(val) == i) {
	// 			cerr << i << " " << val << "\n";
	// 			break;
	// 		}
	// 	}
	// }
	int ma = 0;
	for (int i = 1; i <= 1e6; ++ i) {
		int tmp = countDiv(i);
		ma = max(ma, tmp);
		cerr << i << "  " << tmp << " " << ma << "\n";
	}
}