#include <bits/stdc++.h>
using namespace std;

int tc, y, v, b;
char x, u, a;

bool check(int a, int b) {
	return ('A' <= a && a <= 'H' && 1 <= b && b <= 8);
}

int main() {
	cin >> tc;
	while (tc --) {
		cin >> x >> y >> u >> v;

		if ('a' <= x && x <= 'z') x += 'A' - 'a';
		if ('a' <= u && u <= 'z') u += 'A' - 'a';

		if ((x + y + u + v) % 2 == 1) {
			cout << "Impossible\n";
		} else {
			//  0 move
			if (x == u && y == v) {
				cout << "0 " << x << ' ' << y << '\n';
				continue;
			}
			// 1 move
			if (x + y == u + v || x - y == u - v) {
				cout << "1 " << x << ' ' << y << ' ' << u << ' ' << v << '\n';
				continue;
			}

			// 2 moves
			a = ((u + v) + (x - y)) / 2;
			b = ((u + v) - (x - y)) / 2;
			if (!check(a, b)) {
				a = ((x + y) + (u - v)) / 2;
				b = ((x + y) - (u - v)) / 2;
			}
			cout << "2 " << x << ' ' << y << ' ' << a << ' ' << b << ' ' << u << ' ' << v << '\n';
		}
	}
}