#include <bits/stdc++.h>
using namespace std;

int main() {
	int c;
	cin >> c;
	int res = 100;
	int current = 100;
	for (int i = 0; i < c; ++ i) {
		int x;
		cin >> x;
		current += x;
		res = max(res, current);
	}
	cout << res;
}