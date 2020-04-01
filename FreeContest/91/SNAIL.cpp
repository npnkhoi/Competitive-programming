#include <bits/stdc++.h>
using namespace std;

long long n, t, res;

int main() {
	cin >> n >> t;
	res = 2 * (n / 4);
	// cerr << res << "\n";
	if (n % 4 == 1) res -= (n + 1) / 2;
	else if (n % 4 == 2) res -= 2 * (n / 2);
	else if (n % 4 == 3) res += - n / 2 + 1;
	cout << t + res;
}