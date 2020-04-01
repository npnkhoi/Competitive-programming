#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];
int n;

int main() {
	freopen("MARCH.inp", "r", stdin);
	freopen("MARCH.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != 'X') {
			if ((y + 1) % 2 == (s[i] == 'L')) {
				x ++;
				y ++;
			} else {
				x ++;
				y += 2;
				// cerr << "add\n";
			}
		} else {
			y ++;
		}
	}
	if (y % 2) {
		y ++;
		x ++;
	}
	printf("%.7lf", (double) 100 * x / y);
}