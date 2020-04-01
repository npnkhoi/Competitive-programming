#include <bits/stdc++.h>
using namespace std;

long long a, b, x, y;
bool flag;
string line;

bool perfectSquare(long long x) {
	long long tmp = sqrt(x);
	return tmp * tmp == x;
}

void calc(long long s, long long p, long long div) {
	long long delta = s * s - 4 * p;
	if (delta < 0 || !perfectSquare(delta)) return;
	delta = sqrt(delta);
	if (s - delta < 0 || (s + delta) % 2) return;
	x = (s - delta) / 2;
	y = (s + delta) / 2;
	if (x + y == a && x * (y / __gcd(x, y)) == b) {
		printf("%lld %lld\n", x, y);
		flag = 1;
	}
}

int main() {
	// freopen("D.inp", "r", stdin);
	while (getline(cin, line)) {
		istringstream iss(line);
		iss >> a >> b;
		// scanf(" %lld", &b);
		// cerr << " -- " << a << " " << b << "\n";
		if (a == 0 || b == 0) break;
		flag = 0;
		for (long long i = 1; i <= sqrt(a); ++ i) {
			calc(a, b * i, i);
			if (flag) break;
			calc(a, b * (a / i), a / i);
			if (flag) break;
		}
		if (!flag) printf("No Solution\n");
	}
}