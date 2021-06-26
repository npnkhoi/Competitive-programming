#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc, n;
	cin >> tc;
	while (tc --) {
		cin >> n;
		int a = n / 2, b = n - a;
		cout << 1LL * (a - 1) * (b - 1) << '\n';
	}
}