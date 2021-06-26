#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	long long res, a, b, c, p;
	cin >> tc;
	while (tc --) {
		cin >> p >> a >> b >> c;
		res = 4e18;
		res = min(res, (p + a - 1) / a * a);
		res = min(res, (p + b - 1) / b * b);
		res = min(res, (p + c - 1) / c * c);
		cout << res - p << '\n';
	}	
}