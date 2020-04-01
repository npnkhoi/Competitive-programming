#include <bits/stdc++.h>
using namespace std;

int tc, m, a, b;

int main() {
	freopen("KFIB.inp", "r", stdin);
	freopen("KFIB.ans", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d", &m, &a, &b);
		int x = 0, y = 1 % m, timer = 0;
		// cerr << x << " " << y << "\n";
		while (x != a || y != b) {
			y = (x + y) % m;
			x = (y - x + m) % m;
			timer ++;
			// cerr << x << " " << y << "\n";
			if (timer > 6 * m) break;
		}
		if (timer > 6 * m) printf("-1\n");
		else printf("%d\n", timer);
	}	
}