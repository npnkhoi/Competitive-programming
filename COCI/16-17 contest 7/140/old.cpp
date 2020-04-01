#include <bits/stdc++.h>
using namespace std;

int sign(int x) {
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

void move(int a, int b, int c) {
	int u = -1, v, t, m, n, p;
	if (x[a] < x[b] && y[a] < y[b]) u = a; v = b, t = c;
	if (x[a] < x[c] && y[a] < y[c]) u = a; v = c, t = b;
	if (x[b] < x[a] && y[b] < y[a]) u = b; v = a, t = c;
	if (x[b] < x[c] && y[b] < y[c]) u = b; v = c, t = a;
	if (x[c] < x[a] && y[c] < y[c]) u = c; v = a, t = b;
	if (x[c] < x[b] && y[c] < y[b]) u = c; v = b, t = a;
	if (u != -1) {
		while (x[a] < 0 || x[b] < 0 || x[c] < 0 || y[a] < 0 || y[b] < 0 || y[c] < 0) {
			ans.push_back({v, t, u});
			ans.push_back({v, u, t});
			m = u, n = v, p = t;
			u = n; v = p; t = m;
		}
		return;
	}
	if ()
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d %d", &x[i], &y[i]);
		if (x[i] < 0 || y[i] < 0) {
			v.push_back(i);
		} else {
			correct = i;
		}
	}
	while (v.size() > 3) {
		int x = v.back(); v.pop_back();
		int y = v.back(); v.pop_back();
		int z = v.back(); v.pop_back();
		move(x, y, z);
		correct = x;
	}
	if (v.size() == 1) {
		int x = v.back();
		for (int i = 1; i <= n; ++ i) {
			if (i != x && i != correct) {
				correct2 = i;
				break;
			}
		}
		move(x, correct, correct2);
	} else if (v.size() == 2) {
		move(v[0], v[1], correct);
	}
}