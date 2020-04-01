#include <bits/stdc++.h>
using namespace std;

const vector<int> dollarBills = {1, 2, 5, 10, 20, 50, 100};
const vector<int> euroBills = {5, 10, 20, 50, 100, 200};

int n, d, e, res;

int main() {
	scanf("%d%d%d", &n, &d, &e);
	res = n;
	for (int j = 0; j <= n / 5 / e; ++j) {
		int rest = (n - j * 5 * e) % d;
		res = min(res, rest);
	}
	cout << res;
}