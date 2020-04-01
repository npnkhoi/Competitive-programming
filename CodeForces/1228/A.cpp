#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
	set<int> s;
	while (x > 0) {
		if (s.find(x % 10) != s.end())
			return false;
		s.insert(x % 10);
		x /= 10;
	}
	return true;
}

int main() {
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; ++ i) {
		if (check(i)) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}
