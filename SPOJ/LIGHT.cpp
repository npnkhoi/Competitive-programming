#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int mask = 0; mask < (1 << n); mask ++) { // mask: 0 -> (2^n - 1)

		for (int i = n-1; i >= 0; -- i) {
			cout << ((mask >> i) & 1) << ' ';
		}
		cout << '\n';

	}
}