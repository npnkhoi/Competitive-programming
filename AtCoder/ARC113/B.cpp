#include <bits/stdc++.h>
using namespace std;

int mu(int a, int b, int m) {
	a = a % m;
	if (a == 0) return 0;
	if (b == 0) return 1;

	int res = mu(a, b/2, m);
	res = res * res % m;
	if (b % 2) res = res * a % m;
	return res;
}

int period(int a, int m) {
	a %= m;
	int init = a;
	int res = 0;
	while (1) {
		a = a * init % m;
		res ++;
		if (a == init) break;
	}
	return res;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int a_period = period(a, 10);
	// cerr << a_period << '\n';
	int new_exp = mu(b, c, a_period);
	if (new_exp == 0) {
		new_exp = a_period;
	}
	// cerr << new_exp << '\n';
	cout << mu(a, new_exp, 10);
}