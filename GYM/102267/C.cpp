#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, x;
	cin >> s >> x;
	int res = 1;
	while (1) {
		s /= x;
		if (s == 0) break;
		res ++;
	}
	cout << res;
}