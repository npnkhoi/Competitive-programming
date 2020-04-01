#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, g, n;
	cin >> b >> g >> n;
	b = min(b, n);
	g = min(g, n);
	cout << max(1, b + g + 1 - n);
}