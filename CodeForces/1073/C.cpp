#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, x, y;
char s[N];

int hor[N], ver[N];

int sum(int s[], int l, int r) {
	if (l > r) return 0;
	return s[r] - s[l - 1];
}

bool check(int d) {
	// cerr << " n- d + 1 = " << n - d + 1 << "\n";
	for (int l = 1; l <= n - d + 1; ++ l) {
		// cerr << "l = " << l << "\n";
		int r = l + d - 1;
		// cerr << abs(sum(hor, 1, l - 1) + sum(hor, r + 1, n) - x) + 
		// 	abs(sum(ver, 1, l - 1) + sum(ver, r + 1, n) - y) << "\n";
		if (abs(sum(hor, 1, l - 1) + sum(hor, r + 1, n) - x) + 
			abs(sum(ver, 1, l - 1) + sum(ver, r + 1, n) - y) <= r - l + 1) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%d%d", &x, &y);

	for (int i = 1; i <= n; ++ i) {
		hor[i] = hor[i - 1];
		ver[i] = ver[i - 1];
		if (s[i] == 'L') hor[i] --;
		if (s[i] == 'R') hor[i] ++;
		if (s[i] == 'U') ver[i] ++;
		if (s[i] == 'D') ver[i] --;
	}

	int moves = abs(x) + abs(y);

	if (n < moves || (n - moves) % 2) {
		printf("-1");
		return 0;
	}

	// check(3);

	// cerr << hor[n] << " " << ver[n] << "\n";

	int l, r, mid, bs;
	if ((abs(x - hor[n]) + abs(y - ver[n])) % 4 == 2) {
		l = 1;
		r = (n % 2 ? n : n - 1);
	} else {
		l = 0;
		r = (n % 2 ? n - 1: n);
	}
	l = 0, r = n;
	// cerr << l << " " << r << "\n";
	while (l <= r) {
		// int mid = (l/2 + r/2) / 2 * 2;
		int mid = (l + r) / 2;
		if (check(mid)) {
			bs = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%d", bs);
}