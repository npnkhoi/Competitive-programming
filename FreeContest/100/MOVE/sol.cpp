#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x1, x2, y1, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	if ((x1 - x2) % 2 || (y1 - y2) % 2) cout << -1;
	else cout << abs(x1 - x2) / 2 + abs(y1 - y2) / 2;
}